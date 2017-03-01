#include "inputvalidate.h"
#include <stdio.h>
#include <stdlib.h>


/**
*ѡ����֤
**/
int choiceValidate(int data,int min, int max) {
	if (data<min || data>max)
		return FAIL;
	else return SUCCESS;
}

/**
*������֤
**/
int dataValidate(stuInfo st, pstuInfo h) {
	pstuInfo ptemp = h->next;
	char male[3] = "��";
	char female[3] = "Ů";
	if (st.basisOfComputerScore < 0 || st.basisOfComputerScore>100) {
		fflush(stdin);
		return FAIL;
	}
		
	if (st.cLanguageScore < 0 || st.cLanguageScore>100) {
		fflush(stdin);
		return FAIL;
	}
		
	if (st.englishScore < 0 || st.englishScore>100) {
		fflush(stdin);
		return FAIL;
	}
		
	if (st.mathScore < 0 || st.mathScore>100) {
		fflush(stdin);
		return FAIL;
	}
		
	if ((strcmp(st.sex, male))!=0 && (strcmp(st.sex, female))!=0) {
		fflush(stdin);
		return FAIL;
	}
	while (ptemp != NULL) {
		if (ptemp->stuNum == st.stuNum)
			return PRIMARY_KEY_REPEAT;
		ptemp = ptemp->next;
	}
	return SUCCESS;
}