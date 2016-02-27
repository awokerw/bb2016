void LINK_main() {
	
}

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
	
}

void arcRight(float radius, float degrees, float speed) {
	
}

void squareUp(float speed, float time) {
	motor(MOTOR_RIGHT, speed*-1*LEFT_FULL_POWER*DrFRC);
	motor(MOTOR_LEFT, speed*-1*RIGHT_FULL_POWER*DrFLC);
	msleep(time*1000);
	ao();
}
