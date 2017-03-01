#ifndef INPUTVALIDATE_H_
#define INPUTVALIDATE_H_

#include "base.h"

#define FAIL -1
#define SUCCESS 0
#define PRIMARY_KEY_REPEAT 1



int choiceValidate(int data,int min, int max);

int dataValidate(stuInfo st,pstuInfo h);

#endif // !INPUTVALIDATE_H_