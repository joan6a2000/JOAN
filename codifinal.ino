//start of the buzzer melody we have to declare all the notes
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// this tempo variable is handy for making the song go slower or faster
int tempo = 325;

// the number 2 is the pin we'll use in the arduino
int buzzer = 2;


// This code uses PROGMEM to fit the melody to flash as it was to0 long to fit

const int melody[] PROGMEM = {

  // the melody is from At Doom's Gate 
  //  all this variables and numbers are the notes of the moledy followed by the duration.
  // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
  // the negative numbers are used to represent dotted notes,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //61
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_E4, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_D4, -16, NOTE_E4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_G3, -16,



  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //73
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16, NOTE_B2, -16, NOTE_E3, -16, NOTE_G3, -16, NOTE_C4, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_B3, -16, NOTE_G3, -16, NOTE_E3, -16,
};
//We shortened the melody by cutting most of the notes

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
//end of the melody code

#include <HCSR04.h> //here we inculde a library for our distance sensor
#include <Servo.h> //a library for the servo

Servo myservo;  // we create a servo object to control our servo

UltraSonicDistanceSensor distanceSensor(7, 6); //we initialize the sensor saying the trigger pin is connected to the 7th arduino port and the echopin is on the 6th


int val; // declaring the variable that will contain the distance measured by the sensor
int gir = 180; //we proceed to initialize the variable of our 180º servo this vaiable will determine its position
int i = 0; this variable counts how many times the distance sensor is triggered so we can know later

//stepper
#define STEPPER_PIN_1 10
#define STEPPER_PIN_2 11
#define STEPPER_PIN_3 12
#define STEPPER_PIN_4 13
int step_number = 0;
bool Onestep = false;

void setup() {
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600); //monitor to work
  myservo.attach(8);  // attaches the servo on pin 8 to the servo object
  myservo.write(180); //we move the servo to the 180º initial position
  delay(200); //this delay is for the servo tohave time to arrive to its position
  //stepper
  pinMode(STEPPER_PIN_1, OUTPUT); //attaches the stepperpin1 to the 10th pin and declares it as output
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  //buzzersetup

}
void loop() {

  val = distanceSensor.measureDistanceCm(); //this function will make our sensor size the distance in cm
  Serial.println(val); //this will helpu us keep track of the sensor and whatit is percieving
  if (val < 12 && val >= 1) {  //if the distance the sensor percieves is between 11 and 1 then...
    if (i == 3) { //if it is the 4th time the sensor is triggered then...
      Serial.println("hola"); //just for us to know wich way the code is going
      Serial.println(gir); //to keep track of the position f the servo
      //stepper begins rotating
      for (int a = 0; a < 10240; a++) { //variable a is the steps our stepper takes it is in fullstep and has 2048 steps per revolution so it'll do 5 revolutions before it stops
        OneStep(true); // this bool will decide wich way the stepper goes: true clockwise and false counterclockwise
        delay(2); //minimum delay between steps in ours is 2 miliseconds
      }
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) { //here starts the loop for the buzzer it is inside the if and it plays after the servo is in its position

        // calculates the duration of each note
        divider = pgm_read_word_near(melody + thisNote + 1);
        if (divider > 0) {
          // regular note, just proceed
          noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
          // dotted notes are represented with negative durations
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the time the remaining 10% is a pause
        tone(buzzer, pgm_read_word_near(melody + thisNote), noteDuration * 0.9);

        // Wait for the specief duration before playing the next note.
        delay(noteDuration);

       
        noTone(buzzer);
        //buzzerend

      }
      delay(500); 
      digitalWrite(7, HIGH); //The 4 LEDs will light up
      delay(1000);
      gir = gir + 45; //We augment the gir variable
      myservo.write(0); //servo goes to 0 to drop all of the candy left in the treadmill
      for (int a = 0; a < 10240; a++) {
        OneStep(false);
        delay(2); //minimum delay between steps in ours is 2 miliseconds
      }
      delay(1000);

      //stepperends

      i = 0; //variable i goes back to 0 so we start the cycle again
      gir = 180;
      myservo.write(180);//servo goes back to the beggining at 180º
      delay(8000);// we wait that much so the sensor doesn't get triggered another time by a kid trying to grab its candy
      digitalWrite(7, LOW); //led go off

    }

    else { //the three first times the program willl do this part wich is just dropping some candy by rotating the servo that drives the treadmill
      Serial.println("adeu"); //for us to control what the program is doing
      gir = gir - 30;
      myservo.write(gir);

      i = i + 1; //we add 1 to i so qhen it goes to 4 the if will be true and the other part of the code runs
      delay (5000);
    }
  }
}

void OneStep(bool dir) { //variable dir declares the direction of rotation
  if (dir) {
    switch (step_number) {// this code uses fullsteping instead of microsteping because the loss in torque is not significant
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH); //as the stepper works with 4 coils we turn on one each time so it moves really fast and fluent
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);// next coil turns on
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
    }
  } else {
    switch (step_number) {
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);// same thing just the other direction
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);


    }
  }
  step_number++;
  if (step_number > 3) {
    step_number = 0; //this controls that the code before is repeated on and on till copleting the desired steps
  }
}
