#include"myfile.h"
#include "inputvalidate.h"
#include <stdio.h>
#include <malloc.h>
/**
*���ļ���ȡ���ݷ����ڴ�
**/
int readFromFile(char *fname, pstuInfo h) {
	FILE* fp;
	stuInfo stu;
	int check = 0;
	if ((fp = fopen((const char *)fname, "r")) == NULL) {
		printf("�ļ���ȡʧ�ܣ���ע���ļ����Ƿ����ע���ļ�·���Ƿ���ȷ��\n");
		return -1;
	}
		
	while (!feof(fp))
	{
		fscanf(fp, "%lld %s %s %d %d %d %d", &stu.stuNum,stu.name,stu.sex,&stu.basisOfComputerScore,&stu.mathScore,&stu.englishScore,&stu.cLanguageScore);
		check = dataValidate(stu, h);
		if (check == SUCCESS) {
			insertStuInfo(h, stu);
			printf("�������ȡ�ɹ�:ѧ�ţ�%lld\n", stu.stuNum);
		}	
		else if (check == FAIL)
			printf("����������������:ѧ�ţ�%lld\n", stu.stuNum);
		else if (check == PRIMARY_KEY_REPEAT)
			printf("�������ݺ��ڴ��е�ѧ���ظ�������:ѧ�ţ�%lld\n", stu.stuNum);
	}
	fclose(fp);
	return 0;
}

/**
*���ڴ���ļ������ļ�
**/
int writeToFile(char *fname, pstuInfo h) {
	FILE* fp;
	pstuInfo temp;
	if ((fp = fopen((const char*)fname, "wt+")) == NULL)
		return -1;
	temp = h->next;
	while (temp!=NULL)
	{	
		if(temp->next!=NULL)
			fprintf(fp, "%lld %s %s %d %d %d %d\n", temp->stuNum, temp->name, temp->sex, temp->basisOfComputerScore, temp->mathScore, temp->englishScore, temp->cLanguageScore);
		else
			fprintf(fp, "%lld %s %s %d %d %d %d", temp->stuNum, temp->name, temp->sex, temp->basisOfComputerScore, temp->mathScore, temp->englishScore, temp->cLanguageScore);
		temp = temp->next;
	}
	fclose(fp);
	return 0;
}
