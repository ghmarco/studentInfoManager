#ifndef BASE_H_
#define BASE_H_


#define STU_NUMBER 0
#define STU_NAME 1


 typedef struct StuInfo{
	unsigned long long stuNum;
	char name[10];
	char sex[3];
	int basisOfComputerScore;
	int mathScore;
	int englishScore;
	int cLanguageScore;
	struct StuInfo* next;
}stuInfo, *pstuInfo;



int insertStuInfo(pstuInfo h,stuInfo data);

int deleteStuInfo(pstuInfo h,pstuInfo target);

pstuInfo queryStuInfo(pstuInfo h,void *arg, int mode);

int updateStuInfo(pstuInfo target, stuInfo data);

stuInfo dataInput();

int printOneStuInfo(pstuInfo ps);

int printAll(pstuInfo h);

int freeAll(pstuInfo h);

#endif