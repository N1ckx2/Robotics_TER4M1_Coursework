/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  30 March 2017
 *  
 *  Arduino Activity Servo Motor Activity
 */

#include <Servo.h>

Servo stdservo, cntservo;  // create servo object to control a servo

int pos = 0; //stores the servo position/speed (depending on whic hservo)

void setup() {
  stdservo.attach(5);  //declares servo is at pin 5
  cntservo.attach(3);
}

void loop() {
  for (pos = 0; pos <= 180; pos ++) { // goes from 0 degrees to 180 degrees
    stdservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);
  }

  //control continuous servo
  cntservo.write(180);//full speed clockwise
  delay(2000);
  cntservo.write(90); //stop
  delay(1000);
  cntservo.write(0); //full speed CCW
  delay(2000);
  cntservo.write(90); //stop

  //control standard servo
  for (pos = 180; pos >= 0; pos --) { 
    stdservo.write(pos);            
    delay(15);        

  }
}

