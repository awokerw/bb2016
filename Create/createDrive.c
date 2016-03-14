#include <kipr/botball.h>
#include "createDrive.h"
#include <math.h>
#define get_high_byte2(a) (((a)>>8)&255)
#define get_low_byte2(a) ((a)&255)
int bytecounter = -1;
int BYTES[120];
void create_mybyte(int byte)
{
	if (bytecounter==-1)
	{
		create_write_byte(byte);
	}
	else
	{
		BYTES[bytecounter++] = byte;
		if (bytecounter > 100){
			printf("\n\nERROR: SCRIPT TOO LARGE");
			while(1){msleep(1000);}
		}
	}
}
void create_write_int(int integer)
{
	create_mybyte(get_high_byte2(integer));
	create_mybyte(get_low_byte2(integer));
}

void script_start()
{
    int i;
	bytecounter = 0;
    for(i = 0;i < 120;i++)
      {
        BYTES[i] = -1;
    }
}
void script_end()
{
    int i = 0;
    printf("script %d long\n",bytecounter);
    create_write_byte(152);
    create_write_byte(bytecounter);
    while(i < bytecounter)
      {
        create_write_byte(BYTES[i]);
        printf("%d\n",BYTES[i]);
        i++;
    }
	bytecounter = -1;
	
}
void script_run()
{
    create_write_byte(153);
}

void create_direct(int r_speed, int l_speed)
{
    create_mybyte(145);
    create_write_int(-r_speed);
    create_write_int(-l_speed);
}

void create_stop2()
{
    create_mybyte(137);
    create_write_int(0);
    create_write_int(0);
}

//this is for just good old plain scripting
void create_wait_time(int time)//time is in deciseconds
{
	create_mybyte(155);
	create_mybyte(time);
}
/*void create_special_connect(){
	serial_init();
	create_mybyte(128);
	create_mybyte(132);
	create_power_led(250,254);
	atexit(create_disconnect);
}*/
void create_wait_dist(int dist)//dist is in mm
{
	create_mybyte(156);
	create_write_int(-dist);
}
void create_wait_angle(int angle)//degrees, negative = right
{
	create_mybyte(157);
	create_write_int(angle);
}
void create_wait_event(int event)//see #defines for possible answers.  Use 256-event for the inverse
{
	create_mybyte(158);
	create_mybyte(event);
}

void create_drive_direct_dist(int r_speed, int l_speed, int dist)
{
	create_direct(r_speed,l_speed);
	create_wait_dist(dist);
}
void create_drive_direct_left(int r_speed, int l_speed, int angle)
{
	create_direct(r_speed,l_speed);
	create_wait_angle(angle);
}
void create_drive_direct_right(int r_speed, int l_speed, int angle)
{
	create_direct(r_speed,l_speed);
	create_wait_angle(-angle);
}
void create_right(int angle, int radius, int speed)
{
	create_mybyte(137);
	create_write_int(-speed);
	if (radius == 0){
		create_write_int(1);
	}else{
		create_write_int(radius);
	}
	create_wait_angle(-angle);
}
void create_left(int angle, int radius, int speed)
{
	create_mybyte(137);
	create_write_int(-speed);
	if (radius == 0){
		create_write_int(-1);
	}else{
		create_write_int(-radius);
	}
	create_wait_angle(angle);
}
void create_rightD(int dist, int radius, int speed)
{
	create_mybyte(137);
	create_write_int(-speed);
	if (radius == 0){
		create_write_int(1);
	}else{
		create_write_int(radius);
	}
	create_wait_dist(dist);
}
void create_leftD(int dist, int radius, int speed)
{
	create_mybyte(137);
	create_write_int(-speed);
	if (radius == 0){
		create_write_int(-1);
	}else{
		create_write_int(-radius);
	}
	create_wait_dist(dist);
}
void create_backward(int dist, int speed)//DIST IS IN MM!!!!!!!111
{
	create_direct(speed,speed);
	create_wait_dist(dist);
}
void create_forward(int dist, int speed)
{
	create_direct(-speed,-speed);
	create_wait_dist(-dist);
}
void create_crash()
{
	create_mybyte(7);
}

void output_sen_0()
{
	create_mybyte(147);
	create_mybyte((1*1)+(1*2)+(1*4));//pin 19,7,20/output 0,1,2
}

void stop_output()
{
	create_mybyte(147);
	create_mybyte(0);
}

void create_send(){
	//gogo OI mode data!
	create_mybyte(142);
	create_mybyte(35);
	
}
void create_recieve(){
	char buffer[1];
	char *bptr = buffer;
	create_read_block(bptr,1);
	printf("read:%d\n",buffer[0]);
}

// blocks program until create finishes
void create_block()
{
	create_stop();
	create_send();
	create_recieve();
}
/*void create_motors(int byte){
	create_mybyte(138);
	create_mybyte(byte);
	//1*(pin 23)+2*(pin 22)+4*pin(24)
	//so, pin 24 on = send 4
	//off = send 0
}*/
//so long as we are connected to the controller, no reason to use the direct motor command instead of this one
void create_motors(int speed)//speed is from 0 to 128 inclusive
{
	create_mybyte(144);
	create_mybyte(speed);
	create_mybyte(speed);
	create_mybyte(speed);
}

void create_wait_sen0()
{
	output_sen_0();
	create_wait_event(SEN_0);
	stop_output();
}

void create_print_battery()
{
    create_mybyte(149);
    create_mybyte(2);
    create_mybyte(3);
    create_mybyte(34);
	
	
	char buffer[11];
	char *bptr = buffer;
	create_read_block(bptr,11);
	
	int voltage  = buffer[1]*256+buffer[2];
	int current  = (((buffer[3]&&0xFF)*256)+buffer[4])*(buffer[3]>>7);
	int charge   = buffer[6]*256+buffer[7];
	int capacity = buffer[8]*256+buffer[9];
	
    /*CREATE_WAITFORBUFFER(11,-11)
      gc_charge_state=s_read_byte();0
    gc_batt_voltage=s_read_byte()*256;1
    gc_batt_voltage=gc_batt_voltage+s_read_byte();2
    gc_current_flow=s_read_byte()*256;3
    gc_current_flow=gc_current_flow+s_read_byte();4
    gc_batt_temp==s_read_byte();5
    gc_batt_charge=s_read_byte()*256;6
    gc_batt_charge=gc_batt_charge+s_read_byte();7
    gc_batt_capacity=s_read_byte()*256;8
    gc_batt_capacity=gc_batt_capacity+s_read_byte();9
    gc_charge_source=s_read_byte();10//1 if charger 2 if home base 0 if no charge source
	*/
	printf("%dmV,%dmA,%d/%d\n",voltage,current,charge,capacity);
}


/*void create_connectauto(){//automatically connects with a servo on the power button
	if (!create_connect_once()){
		CREATE_POWERPRESS();
		msleep(500);
		CREATE_POWERUNPRESS();
		msleep(500);
		disable_servo(serv);
		create_connect_once();
	}
}
void create_off(){
	CREATE_POWERPRESS();
	msleep(200);
}*/

#define lcliff get_create_lcliff_amt(.002)
#define rcliff get_create_rcliff_amt(.002)
void create_lineup(){//lines up the create on a black line
	int done = 0;
	float tstart = seconds();
	while(done < 4){//WORK ON THIS
		msleep(5);
		int lspd,rspd;
		lspd = rspd = 0;
		if (lcliff > 800) lspd = 20;
		if (lcliff < 500) lspd = -20;
		if (rcliff > 800) rspd = 20;
		if (rcliff < 500) rspd = -20;
		
		if (seconds()-tstart > 4){lspd/=2;rspd/=2;}
		if (seconds()-tstart > 6){
			create_stop();
			return;//failure, timeout
		}
		//printf("\n%6d%6d",lcliff,rcliff);
		create_drive_direct(lspd,rspd);
		if (lspd == rspd && lspd == 0)
			done++;
		else
			done=0;
	}
	create_stop();
}
void create_arm_lift(int speed, int distance) {
  	clear_motor_position_counter(ARM);
	motor(ARM, speed);
  	while(digital(TOUCH) == 0 && gmpc(ARM) < (distance*CMTOBEMF) {}
  	ao();
}
void create_arm_touch_top(int speed) {
	motor(ARM, speed);
	while (digital(TOUCH) == 0) {}
	ao();
}
void create_claw_close() {
	set_servo_position(CLAW, CLAW_CLOSE);
	msleep(500);
}
void create_claw_open() {
	set_servo_position(CLAW, CLAW_OPEN); 
	msleep(500);
}