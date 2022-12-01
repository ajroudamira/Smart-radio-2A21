//Libraries
#include <Keypad.h>

//Constants
#define ROWS 4
#define COLS 4

//Parameters
const char kp4x4Keys[ROWS][COLS]  = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
byte rowKp4x4Pin [4] = {5,4,3,2};
byte colKp4x4Pin [4] = {10,6,7,8};

//Variables
Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);

void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
}

void loop() {
  readKp4x4();
}

void readKp4x4() { /* function readKp4x4 */
  //// Read button states from keypad
  char customKey = kp4x4.getKey();
  if (customKey) {
    Serial.println(customKey);
  }
}