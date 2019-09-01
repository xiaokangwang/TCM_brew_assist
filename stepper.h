/*const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;*/
#ifndef STEPPER_H
#define STEPPER_H
//正转顺序
const char tab1[] =
{
  0x01, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x09
};
//反转的顺序
const char tab2[] =
{
  0x01, 0x09, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03
};
void setupstepper(int IN1, int IN2, int IN3, int IN4);
void ctlStepMotor(int angle, char speeds, int IN1, int IN2, int IN3, int IN4);
void StepMotorStop(int IN1, int IN2, int IN3, int IN4);
#endif
