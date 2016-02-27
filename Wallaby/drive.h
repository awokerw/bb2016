//defining stuff 

#define WHELL_DIAMETER 
#define MOTOR_LEFT
#define MOTOR_RIGHT
#define LEFT_FULL_POWER
#define RIGHT_FULL_POWER

#define TREAD_MOTOR 
#define TREAD_SLOW
#define TREAD_FAST

//functions
void enableAllServos();
void treadRun(float speed, float direction);

void driveForward(float distance, float speed);
void driveBackward(float distance, float speed);
void turnLeft(float angle, float speed);
void turnRight(float angle, float speed);
void arcLeft(float radius, float speed);
void arcRight(float radius, float speed);
void squareUp(float speed, float time);
