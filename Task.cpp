#include "Task.h"

bool TaskResult::isNoReturningValue() {
  return (flags & 0x3) == 0x0;
}
bool TaskResult::isIntReturningValue() {
  return (flags & 0x3) == 0x1;
}
bool TaskResult::isFloatReturningValue() {
  return (flags & 0x3) == 0x2;
}
bool TaskResult::isCharReturningValue() {
  return (flags & 0x3) == 0x3;
}


void TaskResult::NoReturningValue() {
  flags = (flags & ~0x3) | 0x0;
}
void TaskResult::IntReturningValue() {
  flags = (flags & ~0x3) | 0x1;
}
void TaskResult::FloatReturningValue() {
  flags = (flags & ~0x3) | 0x2;
}
void TaskResult::CharReturningValue() {
  flags = (flags & ~0x3) | 0x3;
}

bool TaskResult::isEnableIntrrupt() {
  return (flags & 0x4) == 0x4;
}

void TaskResult::EnableIntrrupt() {
  flags = (flags & ~0x4) | 0x4;
}

void TaskResult::DisableIntrrupt() {
  flags = (flags & 0x4);
}
