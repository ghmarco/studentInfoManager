#include"myfile.h"
#include "inputvalidate.h"
#include <stdio.h>
#include <malloc.h>
/**
*从文件读取数据放入内存
**/
int readFromFile(char *fname, pstuInfo h) {
	FILE* fp;
	stuInfo stu;
	int check = 0;
	if ((fp = fopen((const char *)fname, "r")) == NULL) {
		printf("文件读取失败，请注意文件名是否出错，注意文件路径是否正确。\n");
		return -1;
	}
		
	while (!feof(fp))
	{
		fscanf(fp, "%lld %s %s %d %d %d %d", &stu.stuNum,stu.name,stu.sex,&stu.basisOfComputerScore,&stu.mathScore,&stu.englishScore,&stu.cLanguageScore);
		check = dataValidate(stu, h);
		if (check == SUCCESS) {
			insertStuInfo(h, stu);
			printf("数据项读取成功:学号：%lld\n", stu.stuNum);
		}	
		else if (check == FAIL)
			printf("此项数据有误请检查:学号：%lld\n", stu.stuNum);
		else if (check == PRIMARY_KEY_REPEAT)
			printf("此项数据和内存中的学号重复已舍弃:学号：%lld\n", stu.stuNum);
	}
	fclose(fp);
	return 0;
}

/**
*从内存把文件存入文件
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
