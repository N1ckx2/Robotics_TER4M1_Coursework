/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  29 March 2017
 *  
 *  Arduino Photoresistor activity
 */

int resistPin = 0; //photo resistor pin
int LED = 5; //led pin
int val = 0; //read value

void setup() {
  //set up pins
  pinMode(LED, OUTPUT);
  pinMode(resistPin, INPUT);

  //begin serial monitor to verify readings
  Serial.begin(9200);
}

void loop() {
  val = analogRead(resistPin); //read photoresistor reading
  Serial.println(val); //print value onto serial monitor
  val = map(val, 700, 950, 0, 255); //scale value based on lighting
  analogWrite(LED, val); //output that brightness to LED
}
