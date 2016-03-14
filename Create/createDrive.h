#include <math.h>
/*#define SERV_CREATEPOWER 3
#define CREATE_POWERPRESS(); {enable_servo(SERV_CREATEPOWER);set_servo_position(SERV_CREATEPOWER,down);}
#define CREATE_POWERUNPRESS(); {set_servo_position(SERV_CREATEPOWER,up);}*/

//required for buffering and scripting
#define WHEEL_DROP 1
#define CLIFF 10
#define BUMP 5
#define LEFT_BUMP 6
#define RIGHT_BUMP 7
#define BUTTON_ADVANCED 16
#define BUTTON_PLAY 17//TODO: finish all events.  p16 of create docs
#define SEN_0 18
#define FAST 250
#define SLOW 200
#define VSLOW 50 

#define WHEEL_DIAMETER 1.75
#define PI 3.1415926
#define CMTOBEMF (866/PI*WHEEL_DIAMETER))

#define ARM 8
#define CLAW 0
#define TOUCH 9

#define UP_DOWN_DIST 500
#define CLAW_CLOSE 0
#define CLAW_OPEN 1000

//#define get_high_byte2(a) (((a)>>8)&255)
//#define get_low_byte2(a) ((a)&255)
void create_mybyte(int byte);
void create_write_int(int integer);


void script_start();
void script_end();
void script_run();

void create_direct(int l_speed, int r_speed);

//this is for just good old plain scripting
void create_wait_time(int time);//time is in deciseconds
/*void create_special_connect*/
void create_wait_dist(int dist);//dist is in mm
void create_wait_angle(int angle);//degrees, negative = right
void create_wait_event(int event);//see #defines for possible answers.  Use 255-event for the inverse

void create_drive_direct_dist(int r_speed, int l_speed, int dist);
void create_drive_direct_left(int r_speed, int l_speed, int angle);
void create_drive_direct_right(int r_speed, int l_speed, int angle);
void create_right(int angle, int radius, int speed);
void create_left(int angle, int radius, int speed);
void create_leftD(int dist, int radius, int speed);
void create_rightD(int dist, int radius, int speed);
void create_forward(int dist, int speed);
void create_backward(int dist, int speed);
void create_crash();

void output_sen_0();

void stop_output();

void create_send();
void create_recieve();

// blocks program until create finishes
void create_block();
//void create_motors(int byte){
//so long as we are connected to the controller, no reason to use the direct motor command instead of this one
void create_motors(int speed);//speed is from 0 to 128 inclusive
void create_wait_sen0();//wait for light plugged into digital input 0

void create_print_battery();
/*void create_connectauto();
void create_off();*/

void create_lineup();

//main
void create_main();

//arm stuff
void create_arm_lift(int speed, int distance);
void create_arm_touch_top(int speed);
void create_claw_close();
void create_claw_open();