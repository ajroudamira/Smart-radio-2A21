#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define Password_Length 4 
#include<Servo.h>
Servo s1;

char Data[Password_Length]; 
byte data_count = 0, master_count = 0;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){
  lcd.init(); 
  lcd.backlight();
s1.attach(10);
       

}

void loop(){

  lcd.setCursor(0,0);
  lcd.print("Enter Password:");
  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    lcd.setCursor(data_count,1); 
    lcd.print(Data[data_count]); 
    data_count++; 
    }

  if(data_count == Password_Length){
    lcd.clear();
Serial.write(Data[data_count]);
String s=Serial.readString();
      lcd.print(s);
if(s!="MOT DE PASSE INCORRECTE")
    {
s1.write(45);
delay(5000);
s1.write(135);
delay(5000);
exit(0);


      
      }
 
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}
