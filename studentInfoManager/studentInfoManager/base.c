#include "base.h"
#include <malloc.h>
#include<stdio.h>
#include<string.h>



/**
*入口参数：h 链表的头结点；
*          data 要插入的数据；
*返回值：插入结果，成功返回0；
**/
int insertStuInfo(pstuInfo h, stuInfo data) {
	pstuInfo p;
	p = h->next;

	h->next = (pstuInfo)malloc(sizeof(stuInfo));
	memset(h->next, 0, sizeof(stuInfo));
	h->next->stuNum = data.stuNum;
	strcpy(h->next->name , data.name);
	strcpy(h->next->sex , data.sex);
	h->next->basisOfComputerScore = data.basisOfComputerScore;
	h->next->mathScore = data.mathScore;
	h->next->englishScore = data.englishScore;
	h->next->cLanguageScore = data.cLanguageScore;
	
	h->next->next = p;

	return 0;
}

/**
*入口参数：h 链表头结点；
*          target 要删除的目标结点；
*返回值：删除是否成功，成功返回0,失败返回1；
**/
int deleteStuInfo(pstuInfo h, pstuInfo target) {
	pstuInfo before,temp;
	temp = h;
	while (temp != NULL&&temp->next != target)
		temp = temp->next;
	if (temp == NULL)
		return -1;
	else
	{
		before = temp;
		temp = temp->next;
		before->next = temp->next;
		free(temp);
		return 0;
	}

}

/**
*入口参数：h 头结点；
*          arg 查询参数，为姓名或者学号的void型指针；
*          mode 查询模式，为STU_NUMBER 按学号查询，为STU_NAME 按姓名查询；
*返回值：查询成功返回目标结点指针，失败返回NULL；
**/
pstuInfo queryStuInfo(pstuInfo h, void *arg, int mode) {
	pstuInfo temp;
	temp = h->next;
	if (mode == STU_NUMBER) {
		long *pl = (long*)arg;
		while (temp != NULL && temp->stuNum != *pl  )
		{
			temp = temp->next;
		}
	}
	else if(mode == STU_NAME)
	{
		char *pS = (char*)arg;
		while ( temp != NULL && (strcmp(temp->name , pS )!=0))
		{
			temp = temp->next;
		}
	}
	if (temp == NULL)
		printf("查询为空\n");
	return temp;
}

/**
*入口参数：target 要修改的目标结点；
*          data   要修改的值；
*返回值：成功返回0；
**/
int updateStuInfo(pstuInfo target, stuInfo data) {
	target->stuNum = data.stuNum;
	strcpy(target->name, data.name);
	strcpy(target->sex , data.sex);
	target->basisOfComputerScore = data.basisOfComputerScore;
	target->mathScore = data.mathScore;
	target->englishScore = data.englishScore;
	target->cLanguageScore = data.cLanguageScore;

	return 0;
}


/**
*打印一个学生信息
**/
int printOneStuInfo(pstuInfo ps) {
	printf("%lld \t\t %s\t\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n", ps->stuNum, ps->name, ps->sex, ps->basisOfComputerScore, ps->mathScore, ps->englishScore, ps->cLanguageScore);
	return 0;
}

/**
*打印所有学生信息
**/
int printAll(pstuInfo h) {
	printf("***********************************************所有成绩信息***********************************************\n");
	printf("学号\t\t姓名\t\t性别\t\t计算机基础\t\t高数\t\t英语\t\tC语言\n");
	pstuInfo temp = h->next;
	if (temp == NULL)
		printf("信息为空\n");
	else while (temp != NULL) {
		printOneStuInfo(temp);
		temp = temp->next;
	}
	return 0;
}

/**
*释放链表所有资源
**/
int freeAll(pstuInfo h) {
	pstuInfo temp = h, ps = h;
	while (temp != NULL) {
		ps = temp->next;
		free(temp);
		temp = ps;
	}
	return 0;
}

/**
*数据输入
**/
stuInfo dataInput() {
	stuInfo temp;
	printf("*请依次输入学生学号、姓名、性别、计算机基础得分、高数得分、英语得分、C语言得分，用空格隔开*\n");
	printf("注意：性别只能选填“男/女”，分数只能在0-100之间，学号不可与已存在的重复..................*\n");
	scanf("%lld %s %s %d %d %d %d", &temp.stuNum, temp.name, temp.sex, &temp.basisOfComputerScore, &temp.mathScore, &temp.englishScore, &temp.cLanguageScore);
	return temp;
}



