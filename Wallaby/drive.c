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
/*void left(float degrees, float radius,float speed){
	check_driving();
	int turnrspeed;
	long turnl=((2*radius+ks)*CMtoBEMF*PI)*(degrees/360.);
	long turnr=((2*radius-ks)*CMtoBEMF*PI)*(degrees/360.);
	if(turnl == 0l) return;
	turnrspeed = round((float)turnr/(float)turnl*speed);
	msleep(30l);
	if(turnl > 0l)
	motor(MOT_LEFT, speed);
	else
	motor(MOT_LEFT, -speed);
	if(turnrspeed < 0) turnrspeed = -turnrspeed;
	if(turnr > 0l)
	motor(MOT_RIGHT, turnrspeed);
	else
	motor(MOT_RIGHT, -turnrspeed);
	turnl += lpos;
	turnr += rpos;
	if(turnr - gmpc(MOT_RIGHT) > 0l){
		if(turnl - gmpc(MOT_LEFT) > 0l){
			while((turnr > gmpc(MOT_RIGHT) && turnrspeed != 0) || turnl > gmpc(MOT_LEFT)){
				if(turnr < gmpc(MOT_RIGHT) - 10l) off(MOT_RIGHT);
				if(turnl < gmpc(MOT_LEFT) - 10l) off(MOT_LEFT);
			}
			}else{
			while((turnr > gmpc(MOT_RIGHT) && turnrspeed != 0) || turnl < gmpc(MOT_LEFT)){
				if(turnr < gmpc(MOT_RIGHT) - 10l) off(MOT_RIGHT);
				if(turnl > gmpc(MOT_LEFT) + 10l) off(MOT_LEFT);
			}
		}
		}else{
		if(turnl - gmpc(MOT_LEFT) > 0l){
			while((turnr < gmpc(MOT_RIGHT) && turnrspeed != 0) || turnl > gmpc(MOT_LEFT)){
				if(turnr > gmpc(MOT_RIGHT) + 10l) off(MOT_RIGHT);
				if(turnl < gmpc(MOT_LEFT) - 10l) off(MOT_LEFT);
			}
			}else{
			while((turnr < gmpc(MOT_RIGHT) && turnrspeed != 0) || turnl < gmpc(MOT_LEFT)){
				if(turnr > gmpc(MOT_RIGHT) + 10l) off(MOT_RIGHT);
				if(turnl > gmpc(MOT_LEFT) + 10l) off(MOT_LEFT);
			}
		}
	}
	drive_off();
	lpos = turnl;
	rpos = turnr;
}
/* \fn void left(int degrees, int radius)
 * \brief turns left degrees degrees at int radius radius
 * \param degrees degrees forward to go
 * \param radius radius at which to turn around
*/
/*void right(float degrees, float radius,float speed){
	check_driving();
	int turnlspeed;
	long turnl=((2*radius-ks)*CMtoBEMF*PI)*(degrees/360.);
	long turnr=((2*radius+ks)*CMtoBEMF*PI)*(degrees/360.);
	if(turnr == 0l) return;
	turnlspeed = round((float)turnl/(float)turnr*speed);
	msleep(30l);
	if(turnr > 0l)
	motor(MOT_RIGHT, speed);
	else
	motor(MOT_RIGHT, -speed);
	if(turnlspeed < 0) turnlspeed = -turnlspeed;
	if(turnl > 0l)
	motor(MOT_LEFT, turnlspeed);
	else
	motor(MOT_LEFT, -turnlspeed);
	turnr += rpos;
	turnl += lpos;
	if(turnl - gmpc(MOT_LEFT) > 0l){
		if(turnr - gmpc(MOT_RIGHT) > 0l){
			while((turnl > gmpc(MOT_LEFT) && turnlspeed != 0) || turnr > gmpc(MOT_RIGHT)){
				if(turnl < gmpc(MOT_LEFT) - 10l) off(MOT_LEFT);
				if(turnr < gmpc(MOT_RIGHT) - 10l) off(MOT_RIGHT);
			}
			}else{
			while((turnl > gmpc(MOT_LEFT) && turnlspeed != 0) || turnr < gmpc(MOT_RIGHT)){
				if(turnl < gmpc(MOT_LEFT) - 10l) off(MOT_LEFT);
				if(turnr > gmpc(MOT_RIGHT) + 10l) off(MOT_RIGHT);
			}
		}
		}else{
		if(turnr - gmpc(MOT_RIGHT) > 0l){
			while((turnl < gmpc(MOT_LEFT) && turnlspeed != 0) || turnr > gmpc(MOT_RIGHT)){
				if(turnl > gmpc(MOT_LEFT) + 10l) off(MOT_LEFT);
				if(turnr < gmpc(MOT_RIGHT) - 10l) off(MOT_RIGHT);
			}
			}else{
			while((turnl < gmpc(MOT_LEFT) && turnlspeed != 0) || turnr < gmpc(MOT_RIGHT)){
				if(turnl > gmpc(MOT_LEFT) + 10l) off(MOT_LEFT);
				if(turnr > gmpc(MOT_RIGHT) + 10l) off(MOT_RIGHT);
			}
		}
	}
	drive_off();
	lpos = turnl;
	rpos = turnr;
}


void forward_arc(float distance, float speed, float arc)
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
}*/

void squareUp(float speed, float time) {
	motor(MOTOR_RIGHT, speed*-1*LEFT_FULL_POWER*DrFRC);
	motor(MOTOR_LEFT, speed*-1*RIGHT_FULL_POWER*DrFLC);
	msleep(time*1000);
	ao();
}
