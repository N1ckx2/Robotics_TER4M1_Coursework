/* Nicholas Vadivelu and Bingran Li
 * Motor Control Assignment
 * TER 4M1
 * 1 May 2017
 */
 
#include <AFMotor.h>

// Declare both motors
AF_DCMotor m2(1);
AF_DCMotor m1(2);

int diff = 20;

void moveMotor(int speed1, int speed2, int duration) {
  //motor speed to 0 to start
  m1.setSpeed(0);
  m2.setSpeed(0);

  //sets forward or backward based on speed
  m1.run(speed1 > 0 ? FORWARD : BACKWARD);
  m2.run(speed2 > 0 ? FORWARD : BACKWARD);

  //absolute values speed
  speed1 *= (speed1 >= 0 ? 1 : -1);
  speed2 *= (speed2 >= 0 ? 1 : -1);

  //moves the motor
  m1.setSpeed(speed1);
  m2.setSpeed(speed2 <= 20 ? 0 : speed2-diff);

  delay(duration);

  //stops motors
  m1.run(RELEASE);
  m2.run(RELEASE);
}

void setup() {
  //allows motors to run
  m1.run(RELEASE);
  m2.run(RELEASE);
}

void square (int side) { //trce a square
  for (int i = 0 ; i < 4 ; i++) { //four sides
    moveMotor(150, 150, side*250);
    moveMotor(200, 0, 600);
  }
}

void circle (int r) { //trace a circle
  moveMotor(250, 20*r, r*500);
}

void wave (int r, int dist) { //creates an oscillating wave with a striaght line disatnce of dist
  for (int i = 0 ; i < r ; i++) {
    moveMotor(250, 20*r, r*250);
    moveMotor(20*r, 250, r*250);
  }
}

void turn (int dist) {
  moveMotor(150, 150, dist*200);
  moveMotor(200, 120, 1000);
  moveMotor(-120, -200, 1000);
  moveMotor(200, 120, 1000);
  moveMotor(150, 150, dist*200);
}

void loop() {
  m1.run(FORWARD);
  m2.run(FORWARD);
  delay(1000);
  turn(10);
  wave(10);
  /*
  delay(1000);
  square(10);
  delay(1000);
  circle(10);
  delay(1000);
  circle(5);
  delay(3000);
  */
}
