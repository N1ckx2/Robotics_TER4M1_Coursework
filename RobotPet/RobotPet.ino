 /*  Nicholas Vadivelu & Bingran Li
 *  TER4M1
 *  Mr. Jay
 *  
 *  Summative Project - Robot Pet
 */
 
#include <AFMotor.h> //for wheels
#include <Servo.h> //to rotate sensor
#include <stdlib.h> //for absolute value

// Declare both motors for wheels
AF_DCMotor m2(1);
AF_DCMotor m1(2);

//servo to rotate sensor
Servo servo;

//Pins
int servoPin = 10;
int ultrasonicPin = 9;
int listenPin1 = 2;
int listenPin2 = 3;
int touchPin1 = 4;
int touchPin2 = 5;
int speakerPin = 7;

// Determines the duration of the turn, depending on battery level and wheel this will be different
double diff = 0.8;
int lTurnTime = 775;
int rTurnTime = 680;

void setup() {
  //allows motors to run
  m1.run(RELEASE);
  m2.run(RELEASE);
  servo.attach(servoPin);
  servo.write(90); // Point straight initially

  //set up the sensor pins
  pinMode(ultrasonicPin, INPUT);
  pinMode(listenPin1, INPUT);
  pinMode(listenPin2, INPUT);
  pinMode(touchPin1, INPUT);
  pinMode(touchPin2, INPUT);
  pinMode(speakerPin, OUTPUT);
}

//function made to easily control the movement of the robot
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
float distance(int pin) {
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

//go straight while avoiding obstacles
void moveStraight() {
  float dist = distance(ultrasonicPin); //gets the distance of the obstacle in front
  int distTravelled = 0;
  if (dist > 10) {//obstacle is a safe distance away
    moveMotor(200, 200, 200);
  } else { //obstacle is close
    moveMotor(200, 0, rTurnTime);//90 degree right turn
    servo.write(0); // Turn servo left
    delay(500);
    while (distance(ultrasonicPin) < 30) { //keep moving sideways until you cross the object
      moveMotor(200, 200, 50);
      distTravelled++;
    }
    moveMotor(200,200,200); // Clear the box
    moveMotor(0, 200, lTurnTime); //turn straight
    delay(500);
    while (distance(ultrasonicPin) < 30) { //keep moving forward until you pass the object
      moveMotor(200, 200, 50);
    }
    moveMotor(200,200,200); // Clear the box
    moveMotor(0, 200, lTurnTime); //turn sideways again
    delay(500);
    for (int i = 0 ; i < distTravelled ; i++) {
      moveMotor(200, 200, 50);
    }
    moveMotor(200,200,200); // Compensate for claering the box earlier
    moveMotor(200, 0, rTurnTime);//90 degree right turn
    servo.write(90); // Point sensor straight
  }
}


//listens for loudest noise, turns towards that sound
void findSound() {
  int leftSound = analogRead(listenPin1);
  int rightSound = analogRead(listenPin2);
  moveMotor(100*rightSound/10, 100*leftSound/10, abs(rightSound - leftSound)*100); //modify equation based on experimental tests
}

//Various tricks are implemented below
void square (int side) { //trce a square
  for (int i = 0 ; i < 4 ; i++) { //four sides
    moveMotor(150, 150, side*250);
    moveMotor(200, 0, 800);
  }
}

void circle (int r) { //trace a circle
  moveMotor(250, 20*r, r*1200);
}

void wave (int r, int dist) { //creates an oscillating wave with a striaght line disatnce of dist
  for (int i = 0 ; i < dist ; i++) {
    moveMotor(250, 20*r, r*125);
    moveMotor(20*r, 250, r*125);
  }
}

//does a 3-point turn for the robot to react to a touch
void turn (int dist) {
  moveMotor(150, 150, dist*200); //moving forward
  moveMotor(120, 200, 1200); //first point of turn 
  moveMotor(-250, -120, 1000); //second point of turn
  moveMotor(120, 200, 1200); //final point of turn
  //moveMotor(150, 150, dist*200); //moving back
}

void playTone(int tone, int duration) { //plays a tone
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) { //plays notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

//checks if the robot was touched, and responds appropriately
void checkTouch() {
  if (digitalRead(touchPin1) == HIGH) { //if the front is touched
    moveMotor(-200, -200, 100); //moves away from sound
    playNote('c', 100); //"growls"
  }

  if (digitalRead(touchPin2) == HIGH) { //if rear is touched
    turn(200); //moves away from sound, turns
    playNote('c', 100); //growls"
  }
}

//will check for tricks
void checkTricks() {
  int x = 0;
  while (x++ < 50) { //will check for tricks for a short period of time
    if (analogRead(listenPin1) >= 250) { //if there is a loud noise, the robot will do one of three tricks
      if (x%3 == 0) 
        square(10);
      else if (x%3 == 1)
        wave(3, 3);
      else 
        circle(10);
      playNote('d', 100);
    }
    delay(10);
  }
}

void loop() {
  checkTouch(); //checks if the robot was touched
  checkTricks(); //check if a trick command was triggered
  findSound(); //figures out which way to turn
  moveStraight(); //moves towards the loud sound source
}
