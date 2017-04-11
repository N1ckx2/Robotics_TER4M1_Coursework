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

//Other required variables
int numPins = 8; //number of pins to make array iteration easier
char notes[] = "cdefgabC "; //notes available on the piano
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; //frequencies that correspond with the notes
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

int getButton() { //gets which button was pressed, returns -1 if none were pressed
  for (int i = 0 ; i < numPins ; i++)
    if (digitalRead(keyPins[i]) == HIGH) return i;
  if (digitalRead(recordPin) == HIGH) return recordPin;
  else if(digitalRead(playPin) == HIGH) return playPin;
  else return -1;
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
  int btnPressed = getButton(); //gets the button that was pressed

  //Initialize recording sequence
  if(btnPressed == recordPin){
    recording = !recording; //turn off if on, on if off

    if (recording) { //if it just started recording, reset variables
      startTime = millis();
      noteCounter = 0; 
    }
    else //finish recording
      recordedTimes[noteCounter] = millis(); //add final time get duration of pause at the end
  }

  //Do playing sequence
  else if(btnPressed == playPin){
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
      if (btnPressed == keyPins[i]) {
        keyPressed = true; 
        if (recording){ //vector add note and add time to the vector
          recordedTones[noteCounter] = tones[i];
          recordedTimes[noteCounter++] = (millis()-startTime);
        }
        playNote(notes[i], 1);//fix this
      }      
    }

    if (!keyPressed && recording){
      recordedTones[noteCounter] = 0; //adds pause
      recordedTimes[noteCounter++] = (millis()-startTime);
    }
    
  }
}
