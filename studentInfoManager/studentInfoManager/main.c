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
		printf("**************������ѡ��*************\n");
		printf("*1������ѧ����Ϣ                    *\n");
		printf("*2��ɾ��ѧ����Ϣ                    *\n");
		printf("*3����ѯѧ����Ϣ                    *\n");
		printf("*4������ѧ����Ϣ                    *\n");
		printf("*5���ɼ�����                        *\n");
		printf("*6����ӡ����ѧ����Ϣ                *\n");
		printf("*7����ȡ/�����ļ�                   *\n");
		printf("*0���˳�ϵͳ                        *\n");
		printf("*************************************\n");
		scanf("%d", &choice);
		if ((choiceValidate(choice, 0, 7)) == FAIL) {
			printf("ѡ��Ƿ���������ѡ��\n");
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
	printf("*������Ҫɾ����ѧ�ţ�\n");
	
	scanf("%ld", &stuNum);

	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("��ѧ�Ų����ڣ�������ѡ��˵�....\n");
		return -1;
	}
	printOneStuInfo(tar);
	deleteStuInfo(h, tar);
	printf("ɾ���ɹ���\n");
	return 0;
}

int queryStu(pstuInfo h) {
	long stuNum = 0;
	pstuInfo tar = NULL;
	printf("*������Ҫ��ѯ��ѧ�ţ�\n");

	scanf("%ld", &stuNum);

	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("��ѧ�Ų����ڣ�������ѡ��˵�....\n");
		return -1;
	}
	printOneStuInfo(tar);
	return 0;
}

int updateStu(pstuInfo h) {
	stuInfo stu;
	long stuNum = 0;
	pstuInfo tar = NULL;
	printf("������Ҫ���ĵ�ѧ��:\n");
	scanf("%ld", &stuNum);
	tar = queryStuInfo(h, (void *)&stuNum, STU_NUMBER);
	if (tar == NULL) {
		printf("��ѧ�Ų����ڣ�������ѡ��˵�....\n");
		return -1;
	}
	printOneStuInfo(tar);
	
	stu = dataInput();

	if ((dataValidate(stu, h)) == FAIL)
		return -1;
	updateStuInfo(tar, stu);

	printf("���³ɹ���\n");
	return 0;
}


int analyse(pstuInfo h) {
	int course,content;
	printf("��ѡ��Ҫ�����Ŀ�Ŀ��\n");
	printf("1�����������\n");
	printf("2������\n");
	printf("3��Ӣ��\n");
	printf("4��C����\n");
	printf("0���������˵�\n");
	scanf("%d", &course);
	if ((choiceValidate(course, 0, 4)) == FAIL) {
		printf("ѡ��Ƿ���������ѡ��\n");
		return -1;
	}
	if (course == 0)
		return 0;
	printf("��ѡ����������ݣ�\n");
	printf("1���ܷ֡�ƽ���֡���߷֡���ͷֺͼ�����\n");
	printf("2��������������\n");
	printf("3���ɼ��ɸߵ�������\n");
	printf("4������ȫ��\n");
	printf("0���������˵�\n");
	scanf("%d", &content);
	if ((choiceValidate(content, 0, 4)) == FAIL) {
		printf("ѡ��Ƿ���������ѡ��\n");
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
	printf("��ѡ�����ļ����ǵ����ļ���\n");
	printf("1�������ļ�\n");
	printf("2�������ļ�\n");
	printf("0���������˵�\n");
	scanf("%d", &choice);
	if ((choiceValidate(choice, 0, 2)) == FAIL) {
		printf("ѡ��Ƿ���\n");
		return -1;
	}
	if (choice == 0)
		return 0;
	printf("�������ļ���(����\\\\����\\)��\n");
	scanf("%s", fname);
	if (choice == 1) {
		readFromFile(fname, h);
		return 0;
	}
	writeToFile(fname, h);
	return 0;

}
