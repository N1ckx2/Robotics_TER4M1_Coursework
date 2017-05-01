/* Nicholas Vadivelu
 * TER 4M1
 * 18 April 2017
 * Mr. Jay
 * Romeo Motor Activity
 */

//Standard PWM DC control
int E1 = 5; //M1 Speed Control
int E2 = 6; //M2 Speed Controlt
int M1 = 4; //M1 Direction Control
int M2 = 7; //M1 Direction Control
  
void stop(void) { //Stop
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}

void advance(char a,char b) { //Move forward
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}

void back_off (char a,char b) { //Move backward
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void turn_L (char a,char b) { //Turn Left
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b) { //Turn Right
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup(void) { 
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
}

void square (int side) { //trave
  for (int i = 0 ; i < 4 ; i++) { //four sides
    advance (255, 255); //moves forward
    delay(side*1000);
    turn_L (200,200); //turns left
    delay(1500);
  }
}

void circle (int r) { //makes a circle of radius r
  turn_L(200, r*10); //the second argument controls radius
  delay(r*1000); //radius controls amount of time the function has to run
}

void wave (int r, int dist) { //creates an oscillating wave with a striaght line disatnce of dist
  turn_L(200, r*10); //one wave
  delay(r*dist*10); 
  turn_R(200, r*10); //opposite wave
  delay(r*dist*10);
}

void turn (int dist) {
  advance (255, 255); 
  delay(dist*1000); //moves forward right distance 
  turn_L(200, 200); //first point of 3 point
  delay(1500);
  back_off (255,255); //second point of 3 point
  delay(5000);
  turn_R(200, 200); //third point of 3 point 
  delay(1500);
  advance(255, 255); //back to start
  delay(dist*1000);
}

void loop(void) {
  advance(255, 255);
  delay(1000);
  square(10);
  circle(10);
  turn (10);
  wave(10,10);
  stop();
  delay(3000);
}
