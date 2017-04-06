/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  3 April 2017
 *  
 *  Arduino Servo with Potentiometer Activity
 */

#include <Servo.h>

Servo servo;

int pot = 4; //potentiometer pin
int value; //variable to be read from pot

void setup() {
  servo.attach(9); //attaches pin 9 to servo
}

void loop() {
  value = analogRead(pot); //reads servo value
  servo.write(map(value, 0, 1023, 0, 180)); //proportionally scales and sets servo to position
  delay(15); //waits for servo
}

