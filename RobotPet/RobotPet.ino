/*  Nicholas Vadivelu & Bingran Li
 *  TER4M1
 *  Mr. Jay
 *  
 *  Summative Project - Robot Pet
 */
 
#include <AFMotor.h> //for wheels
#include <Servo.h> //to rotate sensor

// Declare both motors for wheels
AF_DCMotor m2(1);
AF_DCMotor m1(2);

//servo to rotate sensor
Servo servo;

//Pins
int sensorPin = 9; //ultraosonic sensor pin
int servoPin = 10;

double diff = 0.8;

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
  m2.setSpeed(speed2*diff);

  delay(duration);

  //stops motors
  m1.run(RELEASE);
  m2.run(RELEASE);
}

//calculates distance between robot and object in front of it in cm
float distance(int pin)
{
  unsigned long time;
  unsigned long sizeofpulse;
  float range;

  pinMode(pin, OUTPUT); //return digital pin to OUTPUT mode after reading
  digitalWrite(pin, LOW);
  delayMicroseconds(25);
  digitalWrite(pin, HIGH); //Trig pin pulsed LOW for 25usec
  time = micros(); //record timer
  pinMode(pin, INPUT); //change pin to INPUT to read the echo pulse 
  sizeofpulse = pulseIn(pin, LOW, 18000); //should be approx 150usec, timeout at 18msec
  time = micros() - time - sizeofpulse; // amount of time elapsed since we sent the trigger pulse and detect the echo pulse, then subtract the size of the echo pulse
  range = (time*340.29/2/10000)-3; // convert to distance in centimeters
  return range;
}


void setup() {
  //allows motors to run
  m1.run(RELEASE);
  m2.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  int dist = distance(sensorPin);
}
