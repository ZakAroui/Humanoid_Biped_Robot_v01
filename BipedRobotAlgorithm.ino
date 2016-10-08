#include <Servo.h> 
 
Servo lAnkle;  // Declare the eight servos variables
Servo rAnkle;
Servo lKnee;
Servo rKnee;
Servo lThigh;
Servo rThigh;
Servo lHip;
Servo rHip;

int POS_LA=70, POS_RA=70, POS_LK=75, POS_RK=90, POS_LT=80, POS_RT=65, POS_LH=95, POS_RH=85; // the default positions of the servos
int pos_la,pos_ra, pos_lk, pos_rk, pos_lt, pos_rt, pos_lh, pos_rh; // position holders for the servos
bool en = true;

void setup() // The initialization function of the program
{ 
	Serial.begin(9600);  // Initialize the serial speed rate
  
	lAnkle.attach(3);   // Assign the different pins to each servo
	rAnkle.attach(4); 
	lKnee.attach(5);
	rKnee.attach(6);
	lThigh.attach(44);
	rThigh.attach(45);
	lHip.attach(46);
	rHip.attach(47);

	Reset();          // reset the robot to it's balanced postition
	delay(10000);     // Appropriate time to turn on the power supply
} 
 
void loop(){              // The looped part of the program
	leanLeft(20);         // The different fuction of the walking algorithm
	RightFootUp(40);
	RightFootDown(15);    // Those functions make two steps
	leanRight(20);
        RightFootDown(25);
	leanRight(20);
	LeftFootUp(40);
	LeftFootDown(15);
	leanLeft(20);
        LeftFootDown(25);
	Reset();           // the robot has always go back to its default balanced position
        delay(100);

//        leanLeft(18);
//        leanRight(18);
//        Reset();
//        leanRight(18);
//        leanLeft(18);
//        Reset();
//        Crouch(45);
//        StandUp(45);
//        Reset();
}

/* 	//normalDance();

   //lean to the right
     leanRightWalk();
     delay(1000);
	 
   // raise right foot
     leftFootUp();
     delay(1000);
	 
   //gain balance to the left
     leanBackLeftWalk();
     delay(1000);
	 
   //balance right leg
     rightFootMove();
     delay(1000);
     
         //lean to the left for the second step
//           leanLeftWalk();
//           delay(1000);
//         //raise the right foot
//           rightFootUp();
           //delay(1000000);
//         //gain balance to the right
//           leanBackRightWalk();
           //delay(1000000); */

/* void normalDance(){        // normal dance  Algorithms
  //lean to the left  
     leanLeft();
     delay(1000);
  // lean to the right to the middle
      leanRightM();
      delay(1000);
  //crouch forward
     crouchForward();
     delay(1000);
  //stand back from a crouch
    standBackCrouch();
    delay(1000);
  //lean to the right
      leanRight();
      delay(1000);
  //lean to the left to the middle
      leanLeftM();  
      delay(1000);
  //crouch forward
     crouchForward();
     delay(1000);
  //stand back from a crouch
    standBackCrouch();
    delay(1000);
}

void leanLeft(){
	for(int j=0; j<=20; j++){
		LAnkleOut(j);
		RAnkleIn(j);
		LHipIn(j);
		RHipOut(j);
		delay(100);
    }
}

void leanRightM(){
	for(int j=0; j<=20; j++){
		RAnkleOut(j);
		LAnkleIn(j);
		RHipIn(j);
		LHipOut(j);
		delay(100);
	}
}

void crouchForward(){
	for(int j=0; j<=15; j++){
		LKneeBackward(2*j);
		RKneeBackward(2*j);
		LThighForward(j);
		RThighForward(j);
		delay(100);
    }
}

void standBackCrouch(){
	for(int j=0; j<=15; j++){
		LKneeForward(2*j);
		RKneeForward(2*j);
		LThighBackward(j);
		RTighBackward(j);
		delay(100);
    }
}

void leanRight(){
	for(int j=0; j<=20; j--){
		RAnkleOut(j);
		LAnkleIn(j);
		RHipIn(j);
		LHipOut(j);
		delay(100);
    }
}

void leanLeftM(){
	for(int j=0; j<=20; j++){
		LAnkleOut(j);
		RAnkleIn(j);
		LHipIn(j);
		RHipOut(j);
		delay(100);
    }
}

void leanRightWalk(){
	for(int j=0; j<=15; j++){
		RAnkleOut(j);
		LAnkleIn(j);
		RHipIn(j);
		LHipOut(j);
		delay(100);
    }
}

void leftFootUp(){
	for(int j=0; j<=25; j++){
		LThighForward(2*j);
		LKneeBackward(j);
		delay(100);
    }
}

void rightFootMove(){
	for(int j=0; j<=10; j++){
		LThighBackward(4*j);
		RKneeForward(j);
		RTighBackward(j);
		delay(100);
    }
}

void leanBackLeftWalk(){
	for(int j=6; j<=15; j){
		RAnkleIn(j);
		LAnkleOut(j);
		RHipOut(j);
		LHipIn(j);
		delay(100);
    }
}

void leanLeftWalk(){
	for(int j=1; j<=4; j++){
		RAnkleIn(j);
		LAnkleOut(j);
		RHipOut(j);
		LHipIn(j);
		delay(200);
    }
}

void rightFootUp(){
  for(int j=0; j<=25; j++){
	  RThighForward(j);
	  RKneeBackward(j);
	  delay(100);
    }
}

void leanBackRightWalk(){
	for(int j=0; j>=10; j++){
		RAnkleOut(j);
		LAnkleIn(j);
		RHipIn(j);
		LHipOut(j);
		delay(100);
    }
} */

void Reset()            // the reset function
{
	pos_la=POS_LA;   // assign the default positions to the position holders 
	pos_ra=POS_RA;
	pos_lk=POS_LK;
	pos_rk=POS_RK;
	pos_lt=POS_LT;
	pos_rt=POS_RT;
	pos_lh=POS_LH;
	pos_rh=POS_RH;
	WriteAngles();   // send the appropriate angles to the servos
}

void WriteAngles()        // this function sends the appropriate angles to the servos
{
	lHip.write(pos_lh);  // each specific position is given to the specified servo
	rHip.write(pos_rh);  
	lThigh.write(pos_lt);
	rThigh.write(pos_rt);
	lKnee.write(pos_lk);
	rKnee.write(pos_rk);
	lAnkle.write(pos_la);
	rAnkle.write(pos_ra);
}

void LAnkleIn()           // move the left ankle inward
{
	pos_la= pos_la-1;
	WriteAngles();
}

void LAnkleOut()          // move the left ankle outward
{
	pos_la= pos_la+1;
	WriteAngles();
}

void RAnkleIn()            // move the right ankle inward
{
	pos_ra= pos_ra+1;
	WriteAngles();
}

void RAnkleOut()            // move the right ankle outward
{
	pos_ra= pos_ra-1;
	WriteAngles();
}

void LHipIn()              // move the left hip inward
{
	pos_lh= pos_lh-1;
	WriteAngles();
}

void LHipOut()            // move the left hip outward
{
	pos_lh= pos_lh+1;
	WriteAngles();
}

void RHipIn()              // move the right hip inward
{
	pos_rh= pos_rh+1;
	WriteAngles();
}

void RHipOut()              // move the right hip outward
{
	pos_rh= pos_rh-1;
	WriteAngles();
}

void LKneeForward()          // move the left knee forward
{
	pos_lk= pos_lk+1;
	WriteAngles();
}

void LKneeBackward()          // move the left knee backward
{
	pos_lk= pos_lk-1;
	WriteAngles();
}

void RKneeForward()          // move the right knee forward
{
	pos_rk= pos_rk-1;
	WriteAngles();
}

void RKneeBackward()         // move the right knee backward
{
	pos_rk= pos_rk+1;
	WriteAngles();
}

void LThighForward()           // move the left thigh forward
{
	pos_lt= pos_lt-1;
	WriteAngles();
}

void LThighBackward()            // move the left thigh backward
{
	pos_lt= pos_lt+1;
	WriteAngles();
}

void RThighForward(){              // move the right thigh forward
	pos_rt= pos_rt+1;
	WriteAngles();
}

void RThighBackward(){              // move the right thigh backward
	pos_rt= pos_rt-1;
	WriteAngles();
}

void leanRight(int angle)           // this function makes the robot lean to the right
{
	for(int i=0; i<angle; i++)
	{
		RAnkleOut();
		LAnkleIn();
		RHipIn();
		LHipOut();
		delay(38);
	}
}

void leanLeft(int angle)              // this function makes the robot lean to the left
{
	for(int i=0; i<angle; i++)
	{
		LAnkleOut();
		RAnkleIn();
		LHipIn();
		RHipOut();
		delay(38);
	}
}

void RightFootUp(int angle)            // this function makes the robot raise its right foot up
{
	for(int i=0; i<angle; i++)
	{
		RThighForward();
		RKneeBackward();
		delay(38);
	}
}

void RightFootDown(int angle)            // this function makes the robot lay its right foot down
{
	for(int i=0; i<angle; i++)
	{
		RThighBackward();
		RKneeForward();
		delay(38);
	}
}

void LeftFootUp(int angle)                // this function makes the robot raise its left foot up
{
	for(int i=0; i<angle; i++)
	{
		LThighForward();
		LKneeBackward();
		delay(38);
	}
}

void LeftFootDown(int angle)                // this function makes the robot lay its left foot down
{
	for(int i=0; i<angle; i++)
	{
		LThighBackward();
		LKneeForward();
		delay(38);
	}
}

void RightFootForward(int angle)            // this function makes the robot move its right foot forward
{
	for(int i=0; i<angle; i++)
	{
		RThighForward();
                RThighForward();
		RKneeBackward();
		delay(38);
	}
}

void LeftFootForward(int angle)            // this function makes the robot move its left foot forward
{
	for(int i=0; i<angle; i++)
	{
		LThighForward();
                LThighForward();
		LKneeBackward();
		delay(38);
	}
}

void StretchLeftLeg(int angle)               // this function makes the robot gain its balance with the left leg
{
  for(int i=0; i<angle; i++)
  {
      LKneeBackward();
      LKneeForward();
  }
}

void StretchRightLeg(int angle)              // this function makes the robot gain its balance with the right leg
{
   for(int i=0; i< angle; i++)
   {
       RThighBackward();
       RKneeForward();
   }
}

void StandUp(int angle)
{
    for(int i=0; i<angle; i++)
	{
		LThighBackward();
                RThighBackward();
		LKneeForward();
                RKneeForward();
		delay(20);
	}
}

void Crouch(int angle)
{
        for(int i=0; i<angle; i++)
	{
		LThighForward();
                RThighForward();
		LKneeBackward();
                RKneeBackward();
		delay(20);
	}
}
