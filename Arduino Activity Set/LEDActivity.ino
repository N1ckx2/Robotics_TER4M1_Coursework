/*  Nicholas Vadivelu
 *  TER4M1
 *  Mr. Jay
 *  29 March 2017
 *  
 *  Arduino Activity LED Activity
 */

int ledPins[] = {3, 5, 6, 9, 10, 11}; //6 LED pins
int num = 0, del = 1000, bright = 255; //controls which pin, delay, and brightness
bool dec = true; //controls if the brightness is decreasing or not

void setup() {
  for (int i = 0 ; i < 6 ; i++) //initialize pins
    pinMode(ledPins[i], OUTPUT);
}

void loop() {
  analogWrite(ledPins[num], bright); //lights up led
  if (num == 0) { 
    (dec ? bright -=100 : bright +=100); //increases or decreases brightness for next led
    if (bright == 5 || bright == 255) dec = !dec; //if max/min is reached, switch from inc to dec or viceversa
  }
  delay(del>0 ? del-=50 : del = 1000); //decrease the delay each time to make it go faster
  digitalWrite(ledPins[num++], LOW); //turn off LED
  
  if (num == 6) num = 0; //once it reaches the end, loop back
}
