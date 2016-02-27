void enableAllServos() {
	enable_servos();
	msleep(500);
}

void treadRun(float speed, float direction, float time) {
	motor(TREAD_MOTOR, speed*direction*TREAD_FULL_POWER);
	msleep(time*1000);
	ao();
}

void driveForward(float distance, float speed) {
	clear_motor_position(MOTOR_LEFT);
	clear_motor_position(MOTOR_RIGHT);
	motor(MOTOR_LEFT, speed*LEFT_FULL_POWER*DrFLC);
	motor(MOTOR_RIGHT, speed*RIGHT_FULL_POWER*DrFRC);
	while (get_motor_position_counter(MOTOR_LEFT) < distance*CMTOBEMF && get_motor_position_counter(MOTOR_RIGHT) < distance*CMTOBEMF) {}
	printf("%d\n", get_motor_position_counter(MOTOR_LEFT));
	ao();
}

void driveBackward(float distance, float speed) {
	clear_motor_position(MOTOR_LEFT);
	clear_motor_position(MOTOR_RIGHT);
	motor(MOTOR_LEFT, -speed*LEFT_FULL_POWER*DrFLC);
	motor(MOTOR_RIGHT, -speed*RIGHT_FULL_POWER*DrFRC);
	while (get_motor_position_counter(MOTOR_LEFT) > -distance*CMTOBEMF && get_motor_position_counter(MOTOR_RIGHT) > -distance*CMTOBEMF) {}
	printf("%d\n", get_motor_position_counter(MOTOR_LEFT));
	ao();
}

void arcLeft(float radius, float degrees, float speed) {
	double dr = (degrees/360)*2*PI*radius*Rt;
	clear_motor_position(MOTOR_LEFT);
	clear_motor_position(MOTOR_RIGHT);
}

void arcRight(float radius, float degrees, float speed) {
	double dr = (degrees/360)*2*PI*radius*Lt;
	clear_motor_position(MOTOR_LEFT);
	clear_motor_position(MOTOR_RIGHT);
}
/*void forward_arc(float distance, float speed, float arc)
//arc=positive to right, negative to left
{
	check_driving();
	if(distance < 0l){
		distance = -distance;
	}
	motor(MOT_LEFT,SPDl-arc);
	motor(MOT_RIGHT,SPDr+arc);
	msleep(1);
	long newdist;
	newdist = distance*CMtoBEMF;//conversion ratio
	long l = lpos+newdist;
	long r = rpos+(newdist*rdistmult);
	//printf("%d,%d,%d,%d,%d,%d\n",l,r,lpos,rpos,gmpc(MOT_LEFT),gmpc(MOT_RIGHT));
	motor(MOT_LEFT,((SPDl+arc)/100)*speed);
	motor(MOT_RIGHT,((SPDr-arc)/100)*speed);
	while(gmpc(MOT_LEFT) < l && gmpc(MOT_RIGHT) < r){
		if (gmpc(MOT_LEFT) >= l)
		off(MOT_LEFT);
		if (gmpc(MOT_RIGHT) >= r)
		off(MOT_RIGHT);
	}
	drive_off();
	//printf("%d,%d,%d,%d,%d,%d\n",l,r,lpos,rpos,gmpc(MOT_LEFT),gmpc(MOT_RIGHT));
	lpos = l;
	rpos = r;
	
	/*mrp(MOT_RIGHT,SPDrb,newdist*rdistmultb);
	mrp(MOT_LEFT,SPDlb,newdist);
	bmd(MOT_RIGHT);
	bmd(MOT_LEFT);
}
void backward_arc(float distance, float speed, float arc)
//arc=positive to right, negative to left
{
check_driving();
	if(distance < 0l){
		distance = -distance;
	}
	long newdist;
	newdist = distance*CMtoBEMF;
	long l = lpos-newdist;
	long r = rpos-(newdist*rdistmultb);
	motor(MOT_LEFT,((-SPDlb-arc)/100)*speed);
	motor(MOT_RIGHT,((-SPDrb+arc)/100)*speed);
	while(gmpc(MOT_LEFT) > l && gmpc(MOT_RIGHT) > r){
		if (gmpc(MOT_LEFT) <= l)
		off(MOT_LEFT);
		if (gmpc(MOT_RIGHT) <= r)
		off(MOT_RIGHT);
	}
	drive_off();
	lpos = l;
	rpos = r;
} */

void squareUp(float speed, float time) {
	motor(MOTOR_RIGHT, speed*-1*LEFT_FULL_POWER*DrFRC);
	motor(MOTOR_LEFT, speed*-1*RIGHT_FULL_POWER*DrFLC);
	msleep(time*1000);
	ao();
}
