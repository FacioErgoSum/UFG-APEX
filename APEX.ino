//Includes the library that controls the LED Display
#include "LedControlMS.h"
//Defines the Touch Sensor pin
#define TouchSensor 7
//Defines the LED Display pins
LedControl lc=LedControl(12,11,10,1);
//Defines the Moisture Sensor pins
int sensorPin = A5;
int sensorValue = 0;
//Sets a delaytime
unsigned long delaytime=1000;
//These booleans regulate the state of the display
bool started = false;
bool on = true;
//This boolean is equal to the state of the capacitive button
boolean pressed = LOW;

byte smile[4]={B00000100,B00110010,B01100100,B01100000};
byte surprise[4]={B00001110,B00001010,B01101110,B10010000};
byte meh[4]={B00000100,B00100100,B00100100,B00100000};
byte sad[4]={B00000010,B01100100,B00110010,B00110000};
byte dead[6]={B00001010,B00100100,B00101010,B00100000,B01100000,B01101010};
byte error[8]={B00111100,B01000010,B10100001,B10010001,B10001001,B10000101,B01000010,B00111100};
//Evil Faces
byte esmile[4]={B00000010,B00101010,B01000100,B01000000};
byte elaugh[4]={B00000010,B00101010,B01100100,B01100000};
byte eplain[4]={B00000010,B00101010,B00100100,B00100000};
byte eyell[4]={B00000001,B01101001,B01100010,B01100000};
byte etalk[4]={B00000001,B00101001,B01100010,B01100000};

void setup() {
  //MS Serial Output
  Serial.begin(9600);

  pinMode(TouchSensor, INPUT);
  
  //LED Matrix Setup
  lc.shutdown(0,false);
  lc.setIntensity(0,4);
  lc.clearDisplay(0);
}

void broken() {
  lc.setRow(0,0,error[0]);
  lc.setRow(0,1,error[1]);
  lc.setRow(0,2,error[2]);
  lc.setRow(0,3,error[3]);
  lc.setRow(0,4,error[4]);
  lc.setRow(0,5,error[5]);
  lc.setRow(0,6,error[6]);
  lc.setRow(0,7,error[7]);
}

void happy() {
  lc.setRow(0,0,smile[0]);
  lc.setRow(0,1,smile[1]);
  lc.setRow(0,2,smile[2]);
  lc.setRow(0,3,smile[3]);
  lc.setRow(0,4,smile[3]);
  lc.setRow(0,5,smile[2]);
  lc.setRow(0,6,smile[1]);
  lc.setRow(0,7,smile[0]);
}

void plain() {
  lc.setRow(0,0,meh[0]);
  lc.setRow(0,1,meh[1]);
  lc.setRow(0,2,meh[2]);
  lc.setRow(0,3,meh[3]);
  lc.setRow(0,4,meh[3]);
  lc.setRow(0,5,meh[2]);
  lc.setRow(0,6,meh[1]);
  lc.setRow(0,7,meh[0]);
}

void surprised(){
  lc.setRow(0,0,surprise[0]);
  lc.setRow(0,1,surprise[1]);
  lc.setRow(0,2,surprise[2]);
  lc.setRow(0,3,surprise[3]);
  lc.setRow(0,4,surprise[3]);
  lc.setRow(0,5,surprise[2]);
  lc.setRow(0,6,surprise[1]);
  lc.setRow(0,7,surprise[0]);
}

void dying() {
  lc.setRow(0,0,dead[0]);
  lc.setRow(0,1,dead[1]);
  lc.setRow(0,2,dead[2]);
  lc.setRow(0,3,dead[3]);
  lc.setRow(0,4,dead[4]);
  lc.setRow(0,5,dead[5]);
  lc.setRow(0,6,dead[1]);
  lc.setRow(0,7,dead[0]);
}

void crying() {
  lc.setRow(0,0,sad[0]);
  lc.setRow(0,1,sad[1]);
  lc.setRow(0,2,sad[2]);
  lc.setRow(0,3,sad[3]);
  lc.setRow(0,4,sad[3]);
  lc.setRow(0,5,sad[2]);
  lc.setRow(0,6,sad[1]);
  lc.setRow(0,7,sad[0]);
}

void evilsmile() {
  lc.setRow(0,0,esmile[0]);
  lc.setRow(0,1,esmile[1]);
  lc.setRow(0,2,esmile[2]);
  lc.setRow(0,3,esmile[3]);
  lc.setRow(0,4,esmile[3]);
  lc.setRow(0,5,esmile[2]);
  lc.setRow(0,6,esmile[1]);
  lc.setRow(0,7,esmile[0]);
}

void evillaugh() {
  lc.setRow(0,0,elaugh[0]);
  lc.setRow(0,1,elaugh[1]);
  lc.setRow(0,2,elaugh[2]);
  lc.setRow(0,3,elaugh[3]);
  lc.setRow(0,4,elaugh[3]);
  lc.setRow(0,5,elaugh[2]);
  lc.setRow(0,6,elaugh[1]);
  lc.setRow(0,7,elaugh[0]);
}

void evilplain() {
  lc.setRow(0,0,eplain[0]);
  lc.setRow(0,1,eplain[1]);
  lc.setRow(0,2,eplain[2]);
  lc.setRow(0,3,eplain[3]);
  lc.setRow(0,4,eplain[3]);
  lc.setRow(0,5,eplain[2]);
  lc.setRow(0,6,eplain[1]);
  lc.setRow(0,7,eplain[0]);
}

void evilyell() {
  lc.setRow(0,0,eyell[0]);
  lc.setRow(0,1,eyell[1]);
  lc.setRow(0,2,eyell[2]);
  lc.setRow(0,3,eyell[3]);
  lc.setRow(0,4,eyell[3]);
  lc.setRow(0,5,eyell[2]);
  lc.setRow(0,6,eyell[1]);
  lc.setRow(0,7,eyell[0]);
}

void eviltalk() {
  lc.setRow(0,0,etalk[0]);
  lc.setRow(0,1,etalk[1]);
  lc.setRow(0,2,etalk[2]);
  lc.setRow(0,3,etalk[3]);
  lc.setRow(0,4,etalk[3]);
  lc.setRow(0,5,etalk[2]);
  lc.setRow(0,6,etalk[1]);
  lc.setRow(0,7,etalk[0]);
}

void writeArduinoOnMatrix() {
  if(sensorValue > 0 && sensorValue <= 30) {
    broken();
  } else if(sensorValue > 30 && sensorValue <= 100){
    dying();
  } else if (sensorValue > 100 && sensorValue <= 200) {
    crying();
  } else if (sensorValue > 200 && sensorValue <= 400) {
    plain();
  } else if (sensorValue > 400 && sensorValue <= 650) {
    happy();
  } else if (sensorValue > 650 && sensorValue <= 800) {
    surprised();
  } else {
    broken();
  }
  
}

void loop() {  
  if (started == true){
    delaytime = 3000;
  }
  
  //Read Button
  pressed = digitalRead(TouchSensor);

  if (pressed) {
    if (on == true) {
      lc.clearDisplay(0);
      on = false;
      delay(delaytime);
    } else {
      on = true;
      delay(delaytime);
    }
  }
  
  sensorValue = analogRead(sensorPin);
  delay(delaytime);
  
  if (on == true) {
    //Draw Faces
    writeArduinoOnMatrix();
  }

  started = true;
}
