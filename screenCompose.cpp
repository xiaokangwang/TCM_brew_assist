#include <Arduino.h>
#include<string.h>
#include "screenCompose.h"
#include "config.h"
//#include "memory.h"
void ScreenComposer::FirstLine(char  input[17]) {
  memset(input, 0x20, 16);

  char * outb = input;

  String tartmp = String(TargetTemp, 1);
  int tartmplen = tartmp.length();
  if (tartmplen > 5) {
#ifndef nodebug
    Serial.println("Target Temp Too Long to be shown on screen.");
#endif
  } else {
    int initpos =  5 - tartmplen;
    strcpy(outb + 1, tartmp.c_str());
  }

  Serial.println(stat);

  *(outb + 5) = 0x20;
  memcpy(outb + 6, stat, 4);
  Serial.println(input);

  Serial.println(RemainTime);

  int minu = RemainTime / 60;
  int minuh = (minu / 10) % 10;
  int minul = minu % 10;

  *(outb + 11) = '0' + minuh;
  *(outb + 12) = '0' + minul;

  *(outb + 13) = ':';

  int secu = RemainTime % 60;
  int secuh = ( secu / 10) % 10;
  int secul =  secu % 10;

  *(outb + 14) = '0' + secuh;
  *(outb + 15) = '0' + secul;



}
void ScreenComposer::SecondLine(char  input[17]) {
  memset(input, 0x20, 16);

  char * outb = input;

  String tartmp = String(AmbTemp, 1);
  int tartmplen = tartmp.length();
  if (tartmplen > 5) {
#ifndef nodebug
    Serial.println("Target Temp Too Long to be shown on screen.");
#endif
  } else {
    int initpos =  5 - tartmplen;
    strcpy(outb + 1, tartmp.c_str());
  }

  Serial.println(inputEcho);

  *(outb + 5) = 0x20;
  
  memcpy(outb + 6, inputEcho, 4);
  
  int minu = UsedTime / 60;
  int minuh = (minu / 10) % 10;
  int minul = minu % 10;

  *(outb + 11) = '0' + minuh;
  *(outb + 12) = '0' + minul;

  *(outb + 13) = ':';

  int secu = UsedTime % 60;
  int secuh = ( secu / 10) % 10;
  int secul =  secu % 10;

  *(outb + 14) = '0' + secuh;
  *(outb + 15) = '0' + secul;



}
