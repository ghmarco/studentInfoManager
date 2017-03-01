#include "base.h"
#include <malloc.h>
#include<stdio.h>
#include<string.h>



/**
*��ڲ�����h �����ͷ��㣻
*          data Ҫ��������ݣ�
*����ֵ�����������ɹ�����0��
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
*��ڲ�����h ����ͷ��㣻
*          target Ҫɾ����Ŀ���㣻
*����ֵ��ɾ���Ƿ�ɹ����ɹ�����0,ʧ�ܷ���1��
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
*��ڲ�����h ͷ��㣻
*          arg ��ѯ������Ϊ��������ѧ�ŵ�void��ָ�룻
*          mode ��ѯģʽ��ΪSTU_NUMBER ��ѧ�Ų�ѯ��ΪSTU_NAME ��������ѯ��
*����ֵ����ѯ�ɹ�����Ŀ����ָ�룬ʧ�ܷ���NULL��
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
		printf("��ѯΪ��\n");
	return temp;
}

/**
*��ڲ�����target Ҫ�޸ĵ�Ŀ���㣻
*          data   Ҫ�޸ĵ�ֵ��
*����ֵ���ɹ�����0��
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
*��ӡһ��ѧ����Ϣ
**/
int printOneStuInfo(pstuInfo ps) {
	printf("%lld \t\t %s\t\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n", ps->stuNum, ps->name, ps->sex, ps->basisOfComputerScore, ps->mathScore, ps->englishScore, ps->cLanguageScore);
	return 0;
}

/**
*��ӡ����ѧ����Ϣ
**/
int printAll(pstuInfo h) {
	printf("***********************************************���гɼ���Ϣ***********************************************\n");
	printf("ѧ��\t\t����\t\t�Ա�\t\t���������\t\t����\t\tӢ��\t\tC����\n");
	pstuInfo temp = h->next;
	if (temp == NULL)
		printf("��ϢΪ��\n");
	else while (temp != NULL) {
		printOneStuInfo(temp);
		temp = temp->next;
	}
	return 0;
}

/**
*�ͷ�����������Դ
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
*��������
**/
stuInfo dataInput() {
	stuInfo temp;
	printf("*����������ѧ��ѧ�š��������Ա𡢼���������÷֡������÷֡�Ӣ��÷֡�C���Ե÷֣��ÿո����*\n");
	printf("ע�⣺�Ա�ֻ��ѡ���/Ů��������ֻ����0-100֮�䣬ѧ�Ų������Ѵ��ڵ��ظ�..................*\n");
	scanf("%lld %s %s %d %d %d %d", &temp.stuNum, temp.name, temp.sex, &temp.basisOfComputerScore, &temp.mathScore, &temp.englishScore, &temp.cLanguageScore);
	return temp;
}



