/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  29 March 2017
 *  
 *  Arduino RGB LED activity
 */

int tempPin = 0; //temperature sensor pin
int val = 0; //read value

int red = 3; //red pin
int blu = 5; //blue pin

void setup() {
  //set up pins
  pinMode(resistPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blu, OUTPUT);
  
  Serial.begin(9200); //serial port to view measurements
}

void loop() {
  val = analogRead(tempPin); //read temperature sensor
  Serial.println(val); //print sensor value
  val = map(val, 150, 180, 0, 255); //scale sensor reading
  analogWrite(red, val); //hotter it is, the more red you get
  analogWrite(blu,255-val); //hotter it is, less blue you get
  delay(100); //add delay to reduce noise and flickering
}
