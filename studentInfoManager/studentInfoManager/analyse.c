#include "analysis.h"
#include <stdio.h>
#include <stdlib.h>


#ifndef ULLONG_MAX
#define ULLONG_MAX 18446744073709551615
#endif // !LONG_MAX

/**
*�����Ʒ�������
**/
int sortByScoreOrStuNum(int choice, pstuInfo h) {
	int temp = 0;
	if (choice == STUNUMBER)
		temp = ULLONG_MAX;

	pstuInfo pstu, ptemp0,ptemp1,ptemp2;
	
	for (pstu = h; pstu->next != NULL;) {
		
		for (ptemp1 = pstu; ptemp1->next != NULL; ptemp1 = ptemp1->next) {
			
			switch (choice) {
			case BASISOFCOMPUTER:
				if (temp < ptemp1->next->basisOfComputerScore) {
					temp = ptemp1->next->basisOfComputerScore;
					ptemp0 = ptemp1;
				}
				break;
			case MATH:
				if (temp < ptemp1->next->mathScore) {
					temp = ptemp1->next->mathScore;
					ptemp0 = ptemp1;
				}
				break;
			case ENGLISH:
				if (temp < ptemp1->next->englishScore) {
					temp = ptemp1->next->englishScore;
					ptemp0 = ptemp1;
				}
				break;
			case CLANGUAGE:
				if (temp < ptemp1->next->cLanguageScore) {
					temp = ptemp1->next->cLanguageScore;
					ptemp0 = ptemp1;
				}
				break;
			case STUNUMBER:
				if (temp > ptemp1->next->stuNum) {
					temp = ptemp1->next->stuNum;
					ptemp0 = ptemp1;
				}
				break;
			default:break;
			}
		}

		ptemp2 = ptemp0->next;
		
		ptemp0->next = ptemp2->next;

		ptemp2->next = pstu->next;

		pstu->next = ptemp2;

		pstu = pstu->next;
		
		temp = 0;
		if (choice == STUNUMBER)
			temp = ULLONG_MAX;
	}
		
	return 0;
}


/**
*ͳ�Ƹ��Ƹ������ε���������ӡ
**/
int amountOfScoreSegement(int choice, pstuInfo h) {

	int underSixty = 0, sixtyToSeventy = 0, seventyToEighty = 0, eightyToNighty = 0, nightyToHundred = 0, hundredPoint = 0;
	int score = 0;
	pstuInfo ptemp = h->next;
	
	while (ptemp != NULL) {
		switch (choice)
		{
		case BASISOFCOMPUTER:
			score = ptemp->basisOfComputerScore; 
			break;
		case MATH:
			score = ptemp->mathScore; 
			break;
		case ENGLISH:
			score = ptemp->englishScore;
			break;
		case CLANGUAGE:
			score = ptemp->cLanguageScore; 
			break;
		default:
			break;
		}
		if (score < 60)
			underSixty++;
		else if (score < 70)
			sixtyToSeventy++;
		else if (score < 80)
			seventyToEighty++;
		else if (score < 90)
			eightyToNighty++;
		else if (score < 100)
			nightyToHundred++;
		else if (score == 100)
			hundredPoint++;
		ptemp = ptemp->next;
	}

	switch (choice)
	{
	case BASISOFCOMPUTER:
		printf("********************************************���������������������********************************************\n\n\n");
		break;
	case MATH:
		printf("********************************************����������������********************************************\n\n\n");
		break;
	case ENGLISH:
		printf("********************************************Ӣ�������������********************************************\n\n\n");
		break;
	case CLANGUAGE:
		printf("********************************************C���Ը�����������********************************************\n\n\n");
		break;
	default:
		break;
	}
	printf("60�����£�%d��\n", underSixty);
	printf("60--69�֣�%d��\n", sixtyToSeventy);
	printf("70--79�֣�%d��\n", seventyToEighty);
	printf("80--89�֣�%d��\n", eightyToNighty);
	printf("90--99�֣�%d��\n", nightyToHundred);
	printf("100   �֣�%d��\n", hundredPoint);

	return 0;
}

/**
*ͳ�ƿ�Ŀ�ܷ֡�ƽ���֡���߷֡���ͷ֡���������Ϣ����ӡ
**/
int analyseScore(int choice, pstuInfo h) {

	int score = 0, maxScore = 0, minScore = 100, totalScore = 0, passCount = 0, count = 0;
	float passRate = 0, averageScore = 0;

	pstuInfo ptemp = h->next;
	while (ptemp != NULL) {
		switch (choice)
		{
		case BASISOFCOMPUTER:
			score = ptemp->basisOfComputerScore;
			break;
		case MATH:
			score = ptemp->mathScore;
			break;
		case ENGLISH:
			score = ptemp->englishScore;
			break;
		case CLANGUAGE:
			score = ptemp->cLanguageScore;
			break;
		default:
			break;
		}

		if (score > maxScore)
			maxScore = score;
		if (score < minScore)
			minScore = score;
		totalScore += score;
		if (score > 60)
			passCount++;
		count++;
		ptemp = ptemp->next;
	}

	averageScore = (float)totalScore / count;
	passRate = (float)passCount * 100 / count;

	switch (choice)
	{
	case BASISOFCOMPUTER:
		printf("********************************************����������ɼ�����********************************************\n\n\n");
		break;
	case MATH:
		printf("********************************************�����ɼ�����********************************************\n\n\n");
		break;
	case ENGLISH:
		printf("********************************************Ӣ��ɼ�����********************************************\n\n\n");
		break;
	case CLANGUAGE:
		printf("********************************************C���Գɼ�����********************************************\n\n\n");
		break;
	default:
		break;
	}
	printf("����Ŀ�ܷ֣�%d\n", totalScore);
	printf("����Ŀƽ���֣�%.2f\n", averageScore);
	printf("����Ŀ��߷֣�%d\n", maxScore);
	printf("����Ŀ��ͷ֣�%d\n", minScore);
	printf("����Ŀ�����ʣ�%.2f%%\n", passRate);

	return 0;
}
