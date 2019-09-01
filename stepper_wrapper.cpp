#include "stepper.h"
#include "stepper_wrapper.h"
StepperWrapper::StepperWrapper(int in1, int in2, int in3, int in4) {
  IN1 = in1;
  IN2 = in2;
  IN3 = in3;
  IN4 = in4;
  currentPos = 0;
  setupstepper(IN1, IN2, IN3, IN4);
};

void StepperWrapper::Move(int angle, char speeds) {
  ctlStepMotor(angle, speeds, IN1, IN2, IN3, IN4);
  currentPos += angle;
};

void StepperWrapper::Stop() {
  StepMotorStop(IN1, IN2, IN3, IN4);
};

int StepperWrapper::getCurrentPos() {
  return currentPos;
};

int StepperWrapper::setCurrentPos(int CurrentPos) {
  currentPos = CurrentPos;
};
