#include "analysis.h"
#include "base.h"
#include "inputvalidate.h"
#include "myfile.h"
#include <malloc.h>

#define ADDSTU 1
#define DELETESTU 2
#define QUERYSTU 3
#define UPDATESTU 4
#define ANALYSE 5
#define PRINTALL 6
#define RNS 7
#define EXIT_MAIN 0

void addStu(pstuInfo h);
int deleteStu(pstuInfo h);
int queryStu(pstuInfo h);
int updateStu(pstuInfo h);
int analyse(pstuInfo h);
void printAllStu(pstuInfo h);
int readAndSave(pstuInfo h);

int main() {
	int choice=-1;
	pstuInfo h = (pstuInfo)malloc(sizeof(stuInfo));
	h->next = NULL;
	while (choice!=0) {
		printf("**************请输入选项*************\n");
		printf("*1、插入学生信息                    *\n");
		printf("*2、删除学生信息                    *\n");
		printf("*3、查询学生信息                    *\n");
		printf("*4、更新学生信息                    *\n");
		printf("*5、成绩分析                        *\n");
		printf("*6、打印所有学生信息                *\n");
		printf("*7、读取/保存文件                   *\n");
		printf("*0、退出系统                        *\n");
		printf("*************************************\n");
		scanf("%d", &choice);
		if ((choiceValidate(choice, 0, 7)) == FAIL) {
			printf("选项非法，请重新选择\n");
			continue;
		}
		switch (choice)
		{
		case ADDSTU:
			addStu(h);
			break;
		case DELETESTU:
			deleteStu(h);
			break;
		case QUERYSTU:
			queryStu(h);
			break;
		case UPDATESTU:
			updateStu(h);
			break;
		case ANALYSE:
			analyse(h);
			break;
		case PRINTALL:
			printAllStu(h);
			break;
		case RNS:
			readAndSave(h);
			break;
		default:
			break;
		}
		if (choice == EXIT_MAIN)
			break;
		system("pause");
		system("cls");
	}
	freeAll(h);
	return 0;
}

void addStu(pstuInfo h) {
	stuInfo stu;
	stu = dataInput();
	insertStuInfo(h, stu);
}

int deleteStu(pstuInfo h) {
	long stuNum = 0;
	pstuInfo tar = NULL;
	printf("*请输入要删除的学号：\n");
	
	scanf("%ld", &stuNum);

	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("此学号不存在，请重新选择菜单....\n");
		return -1;
	}
	printOneStuInfo(tar);
	deleteStuInfo(h, tar);
	printf("删除成功！\n");
	return 0;
}

int queryStu(pstuInfo h) {
	long stuNum = 0;
	pstuInfo tar = NULL;
	printf("*请输入要查询的学号：\n");

	scanf("%ld", &stuNum);

	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("此学号不存在，请重新选择菜单....\n");
		return -1;
	}
	printOneStuInfo(tar);
	return 0;
}

int updateStu(pstuInfo h) {
	stuInfo stu;
	long stuNum = 0;
	pstuInfo tar = NULL;
	printf("请输入要更改的学号:\n");
	scanf("%ld", &stuNum);
	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("此学号不存在，请重新选择菜单....\n");
		return -1;
	}
	printOneStuInfo(tar);
	
	stu = dataInput();

	if ((dataValidate(stu, h)) == FAIL)
		return -1;
	updateStuInfo(tar, stu);

	printf("更新成功！\n");
	return 0;
}


int analyse(pstuInfo h) {
	int course,content;
	printf("请选择将要分析的科目：\n");
	printf("1、计算机基础\n");
	printf("2、高数\n");
	printf("3、英语\n");
	printf("4、C语言\n");
	printf("0、返回主菜单\n");
	scanf("%d", &course);
	if ((choiceValidate(course, 0, 4)) == FAIL) {
		printf("选项非法，请重新选择\n");
		return -1;
	}
	if (course == 0)
		return 0;
	printf("请选择分析的内容：\n");
	printf("1、总分、平均分、最高分、最低分和及格率\n");
	printf("2、各分数段人数\n");
	printf("3、成绩由高到低排列\n");
	printf("4、以上全部\n");
	printf("0、返回主菜单\n");
	scanf("%d", &content);
	if ((choiceValidate(content, 0, 4)) == FAIL) {
		printf("选项非法，请重新选择\n");
		return -1;
	}
	switch (content)
	{
	case 0:
		return 0;
		break;
	case 1:
		analyseScore(course, h);
		break;
	case 2:
		amountOfScoreSegement(course, h);
		break;
	case 3:
		sortByScoreOrStuNum(course, h);
		printAll(h);
		break;
	case 4:
		analyseScore(course, h);
		amountOfScoreSegement(course, h);
		sortByScoreOrStuNum(course, h);
		printAll(h);
		break;
	default:
		break;
	}
	return 0;
}

void printAllStu(pstuInfo h) {
	sortByScoreOrStuNum(STUNUMBER,h);
	
	printAll(h);
}

int readAndSave(pstuInfo h) {
	int choice = -1;
	char fname[100] = "\0";
	printf("请选择导入文件还是导出文件：\n");
	printf("1、导入文件\n");
	printf("2、导出文件\n");
	printf("0、返回主菜单\n");
	scanf("%d", &choice);
	if ((choiceValidate(choice, 0, 2)) == FAIL) {
		printf("选择非法！\n");
		return -1;
	}
	if (choice == 0)
		return 0;
	printf("请输入文件名(请以\\\\代替\\)：\n");
	scanf("%s", fname);
	if (choice == 1) {
		readFromFile(fname, h);
		return 0;
	}
	writeToFile(fname, h);
	return 0;

}
