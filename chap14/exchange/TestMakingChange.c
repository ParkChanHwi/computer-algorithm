#include "makingChange.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


int compare(const void* a, const void* b) {
	int _a = *(int*)a;
	int _b = *(int*)b;

	if (_a < _b)
		return 1;

	else return -1;


}


int main(void) {
	int i = 0; 
	int Pay = 0;
	int Price = 0;
	int UnitCount = 0;
	int* CoinUnits = NULL;
	int* Change = NULL;


	printf("동전의 가짓수를 입력하세요 : ");
	scanf("%d", &UnitCount);
	
	CoinUnits = (int*)malloc(sizeof(int) * UnitCount);
	Change = (int*)malloc(sizeof(int) * UnitCount);

	for (i = 0; i < UnitCount; i++) {
		printf("[%d]번째 동전의 단위를 입력하세요 : ", i);
		scanf("%d", &CoinUnits[i]);

	}


	qsort(CoinUnits, UnitCount, sizeof(int), compare);

	printf("물건가격");
	scanf("%d", &Price);


	printf("지불가격");
	scanf("%d", &Pay);



	GetChange(Price, Pay, CoinUnits, Change, UnitCount);

	PrintChange(CoinUnits, Change, UnitCount);
	


}