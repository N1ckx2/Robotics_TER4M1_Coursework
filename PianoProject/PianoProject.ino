/*  Nicholas Vadivelu & Bingran Li
 *  TER4M1
 *  Mr. Jay
 *  7 April 2017
 *  
 *  Arduino Piano Project
 */


//Pins used on Arduino
int keyPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; //piano key pins
int recordPin = 11, playPin = 12, speakerPin = 13; //pins
int numPins = 8; //number of pins to make array iteration easier

//Notes/Tones constants
//char notes[] = "cdefgabC "; //notes available on the piano
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; //frequencies that correspond with the notes

//Debounce Variables
int prevStates[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}; //stores the previous state of the pins
long lastDebounceTime[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //stores the time a particular button was pressed
int debounceDelay = 50; //debounce time, make it higher if flickers, lower if not sensitive enough

//controls playback/playing of notes
bool recording = false; //controls it he arduino is recoridng or not
bool playing = false; //controls if the song is playing
long startTime = 0; //subtracted from the all the recorded times to prevent overflow
long recordedTones[100], recordedTimes[100]; //stores the tones and notes
int noteCounter = 0; //counts the number of notes played

void playTone(int tone, int duration) { //plays a tone
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

/* Unused; tones are always played. 
void playNote(char note, int duration) { //plays notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}*/

/* No Longer used (debounce was implemented)
int getButton() { //gets which button was pressed, returns -1 if none were pressed
  for (int i = 0 ; i < numPins ; i++)
    if (digitalRead(keyPins[i]) == HIGH) return i;
  if (digitalRead(recordPin) == HIGH) return recordPin;
  else if(digitalRead(playPin) == HIGH) return playPin;
  else return -1;
}*/ 

int readBtn(int pin) { //reads button with debounce
  int val = digitalRead(pin); //reads input from pin

  if(val != prevStates[pin]) lastDebounceTime[pin] = millis(); //stores the last time the button was pressed.

  if ((millis() - lastDebounceTime[pin]) > debounceDelay) //if the button was held long enough, return high
    return HIGH;
  else
    return LOW;
}

void setup() {
  //initialize pins
  for (int i = 0 ; i < numPins ; i++)
    pinMode(keyPins[i], INPUT);
  pinMode(recordPin, INPUT);
  pinMode(playPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  //Initialize recording sequence
  if(readBtn(recordPin) == HIGH){
    recording = !recording; //turn off if on, on if off

    if (recording) { //if it just started recording, reset variables
      startTime = millis();
      noteCounter = 0; 
    }
    else //finish recording
      recordedTimes[noteCounter] = millis(); //add final time get duration of pause at the end
  }

  //Do playing sequence
  else if(readBtn(playPin) == HIGH){
    for (int i = 0 ; i < noteCounter ; i++){ //go through all the notes
      if (recordedTones[i] != 0) { //play the note or pause
        playTone(recordedTones[i], recordedTimes[i+1]-recordedTimes[i]);
      } else {
        delay(recordedTimes[i+1]-recordedTimes[i]);
      }
    }
  }

  //Otherwise play normal note
  else {
    boolean keyPressed = false; //if a key wasn't pressed, need to record pause
    for (int i = 0 ; i < numPins ; i++) {
      if (readBtn(keyPins[i]) == HIGH) { //if the current pin button is being pressed
        keyPressed = true; 
        if (recording){ //vector add note and add time to the vector
          recordedTones[noteCounter] = tones[i];
          recordedTimes[noteCounter++] = (millis()-startTime);
        }
        while (readBtn(keyPins[i]) == HIGH) { //play note while the button is held down
          playTone(tones[i], 15);
        }
      }
    }

    if (!keyPressed && recording){ //records pauses
      recordedTones[noteCounter] = 0; //adds pause
      recordedTimes[noteCounter++] = (millis()-startTime);
    }
    
  }
}
