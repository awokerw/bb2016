//defining stuff 

#define gmpc(port) get_motor_position_counter(port)

#define WHEEL_DIAMETER 5.715
#define MOT_LEFT 0
#define MOT_RIGHT 1
#define LEFT_FULL_POWER 100
#define RIGHT_FULL_POWER 100
#define DrFLC 100/LEFT_FULL_POWER //right motor forward tuning constant
#define DrFRC 100/RIGHT_FULL_POWER //left motor forward tuning constant
#define DrBLC 100/LEFT_FULL_POWER
#define DrBRC 100/RIGHT_FULL_POWER

#define TREAD_MOTOR 2
#define TREAD_FULL_POWER 100
#define TREAD_SLOW 40
#define TREAD_FAST 80

#define TC 16.0 //turn constant

#define PI 3.1415926
#define CMTOBEMF (866/(PI*WHEEL_DIAMETER))

//functions
void enableAllServos();
void treadRun(float speed, float direction);

void driveForward(float distance, float speed);
void driveBackward(float distance, float speed);
void arcLeft(float radius, float degrees, float speed);
void arcRight(float radius, float degrees, float speed);
void squareUp(float speed, float time);

//void forward_arc(float distance, float speed, float arc);
//void backward_arc(float distance, float speed, float arc);
//void left(float degrees, float radius,float speed);
///void right(float degrees, float radius,float speed){

void LINK_main();
