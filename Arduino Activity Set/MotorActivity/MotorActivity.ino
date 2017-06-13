/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  29 March 2017
 *  
 *  Arduino Activity Motor Activity
 */
 
int motorPin = 3, sped = 105;

void setup() {
  pinMode(motorPin, OUTPUT); //initialize motor
}

void loop() {
  analogWrite(motorPin, (sped != 255 ? sped+=50 : sped = 5)); //run motor, increasing speed
  delay(5000);
}
