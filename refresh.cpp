#include "refresh.h"
#include "screenCompose.h"



void processiR(unsigned long code, PeripheralArray * pa) {
  unsigned long keynum = -1;
  switch (code) {
    case 0xFF30CF: //1
      keynum = 1;
      break;
    case 0xFF18E7: //2
      keynum = 2;
      break;
    case 0xFF7a85: //3
      keynum = 3;
      break;
    case 0xFF10ef: //4
      keynum = 4;
      break;
    case 0xFF38c7: //5
      keynum = 5;
      break;
    case 0xFF5aa5: //6
      keynum = 6;
      break;
    case 0xFF42bd: //7
      keynum = 7;
      break;
    case 0xFF4ab5: //8
      keynum = 8;
      break;
    case 0xFF52ad: //9
      keynum = 9;
      break;
    case 0xFF6897: //0
      keynum = 0;
      break;
    case 0xFF906f: //EQ
      keynum = 11;
      break;
    case 0xFFe01f: //-
      keynum = 12;
      break;
    case 0xFFa857: //+
      keynum = 13;
      break;
    case 0xFFc23d: //Start/Stop
      keynum = 14;
      break;
  }

  if (keynum <= 9) {
    pa->irb.numInput = pa->irb.numInput * 10;
    pa->irb.numInput += keynum;

    Serial.println(pa->irb.numInput);
  }

  if (keynum == 11) {
    pa->mis.TimeRequired = pa->irb.numInput * 60 * 1000;
    pa->irb.numInput = 0;
  }

  if (keynum == 12) {
    if (pa->mis.state == 0) {
      pa->mis.state = 1; // move left
    } else {
      pa->mis.state = 3; //shuting down
    }

  }

  if (keynum == 13) {
    if (pa->mis.state == 0) {
      pa->mis.state = 2; //move right
    } else {
      pa->mis.state = 3; //shuting down
    }
  }

  if (keynum == 14) {
    if (pa->mis.state == 0) {
      pa->mis.state = 4; //starting
    } else {
      pa->mis.state = 3; //shuting down
    }
  }

}


void checkIr(IRrecv irrecv, PeripheralArray * pa) {

  decode_results results;

  if (irrecv.decode(&results)) //if the ir receiver module receiver data
  {
    Serial.print("irCode: "); //print"irCode: "
    Serial.print(results.value, HEX); //print the value in hexdecimal
    Serial.print(", bits: "); //print" , bits: "
    Serial.println(results.bits); //print the bits
    irrecv.resume(); // Receive the next value

    processiR(results.value, pa);
  }

}

const char explStat[7][5] = {
  {'i', 'd', 'l', 'e'},
  {'m', 'v', 'L', 'E'},
  {'m', 'v', 'R', 'I'},
  {'A', 'B', 'R', 'T'},
  {'S', 'T', 'A', 'R'},
  {'W', 'A', 'T', 'P'},
  {'W', 'A', 'T', 'M'}
};


void refresh(PeripheralArray * pa) {
  ScreenComposer sc;

  float objt = pa->mlx.readObjectTempC();
  sc.TargetTemp = objt;

  float ambt = pa->mlx.readAmbientTempC();
  sc.AmbTemp = ambt;

  checkIr(pa->irrecv, pa);

  strcpy(sc.stat, explStat[pa->mis.state]);

  String s = String(pa->irb.numInput);

  strcmp(sc.inputEcho, s.c_str());

  unsigned long time = millis();

  if (pa->mis.StartTime == 0) {
    sc.RemainTime = pa->mis.TimeRequired / 1000;
  } else {
    sc.RemainTime = (millis() - pa->mis.StartTime - pa->mis.TimeRequired) / 1000;
  }

  if (pa->mis.StartTime == 0) {
    sc.UsedTime = 0;
  } else {
    sc.UsedTime = (pa->mis.TimeRequired) / 1000;
  }
  char  out[17];

  
  

  
  pa->lcd.clear();
  pa->lcd.setCursor(0,0);

  sc.FirstLine(out);
  pa->lcd.print(out);

  sc.SecondLine(out);
  
  pa->lcd.setCursor(0,1);
  pa->lcd.print(out);

  
};
