#ifndef ScreenComposer_H
#define ScreenComposer_H

class ScreenComposer{
  public:
    unsigned int RemainTime=0;
    unsigned int UsedTime=0;
    float TargetTemp=0.0;
    float AmbTemp=0.0;
    bool useFlash;
    char flash[17]={};
    char inputEcho[5]={};
    char stat[5]={};

    void FirstLine(char  input[17]);
    void SecondLine(char  input[17]);
};

#endif
