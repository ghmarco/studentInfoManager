#ifndef ANALYSIS_H_
#define ANALYSIS_H_


#include "base.h"

#define BASISOFCOMPUTER 1
#define MATH 2
#define ENGLISH 3
#define CLANGUAGE 4
#define STUNUMBER 5

int sortByScoreOrStuNum(int choice,pstuInfo h);

int amountOfScoreSegement(int choice, pstuInfo h);

int analyseScore(int choice, pstuInfo h);

#endif // !ANALYSIS_H_