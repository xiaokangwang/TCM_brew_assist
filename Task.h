#ifndef task_H
#define task_H

#define MAX_TASK_SIZEOF 16

#include "Peripherals.h"



class Task {
  public:
    char TaskType = 0;
    bool isElementaryTask();
    char TaskID();
};

static_assert(sizeof(Task) == 1, "Size of Task Differ");


union TaskUnion {
  Task ta;
  char buf[16];
};

class TaskResult {
  public:
    char flags;
    /*
      0B 76543210
             -- => No returning Value
             -+ => Int returning value
             +- => Float returning value
             ++ => Char returning value

      0B 76543210
            +   =>
            -   =>
    */
    union resultValue {
      double fl;
      int   in;
      char ch[4];
    } rv;

    bool isNoReturningValue();
    bool isIntReturningValue();
    bool isFloatReturningValue();
    bool isCharReturningValue();

    void NoReturningValue();
    void IntReturningValue();
    void FloatReturningValue();
    void CharReturningValue();
};

static_assert(sizeof(TaskResult) == 5, "Size of TaskResult is not 5");

class TaskStack {
  public:
    char count;
    TaskUnion tu[MAX_TASK_SIZEOF];
    TaskResult tr;
};



class ElementaryTask: public Task {
  public:
    bool virtual ProcessElementaryTask(struct PeripheralArray * pa , TaskResult * resultBuffer) = 0;
};

class CompoundTask: public Task {
  public:
    bool virtual ProcessCompoundTask(TaskUnion * nextTask , TaskResult * resultBuffer) = 0;
};

static_assert(sizeof(Task) + 2 == sizeof(CompoundTask), "Size of CompoundStack Differ");
static_assert(sizeof(Task) + 2 == sizeof(ElementaryTask), "Size of ElementaryTask Differ");

/*
class DemoCompoundTask: public CompoundTask {
  bool ProcessCompoundTask(TaskStack * ts , TaskResult * resultBuffer);
};*/

#endif
