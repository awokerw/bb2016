//defining stuff 

#define BOT_DIAMETER
#define WHELL_DIAMETER 
#define MOTOR_LEFT
#define MOTOR_RIGHT
#define LEFT_FULL_POWER
#define RIGHT_FULL_POWER
#define DrFLC //right motor tuning constant
#define DrFLR //left motor tuning constant

#define TREAD_MOTOR 
#define TREAD_FULL_POWER
#define TREAD_SLOW
#define TREAD_FAST

#define Rt
#define Lt

#define PI 3.1415926
#define CMTOBEMF (866/(PI*WHEEL_DIAMETER));

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
