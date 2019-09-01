#ifndef STEPPER_WRAPPER_H
#define STEPPER_WRAPPER_H
class StepperWrapper {
  public:
    StepperWrapper(int in1, int in2, int in3, int in4);
    void Move(int angle, char speeds);
    void Stop();
    int getCurrentPos();
    int setCurrentPos(int CurrentPos);
  private:
    int IN1;
    int IN2;
    int IN3;
    int IN4;
    int currentPos;
};
#endif
