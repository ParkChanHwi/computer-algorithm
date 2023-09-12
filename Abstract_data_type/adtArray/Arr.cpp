#include "Arr.h"
#include<stdlib.h>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // 처음에 메모리 공간 8바이트 만큼 할당 (int자료형 2개 저장 목적)
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;

}

void ReleaseArr(tArr* _pArr) // 메모리 해제
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Add_Data(tArr* _pArr, int data) // 데이터 추가
{
	if (_pArr->iMaxCount <= _pArr->iCount) {

		Reallocate(_pArr); // 재할당
	}

	_pArr->pInt[_pArr->iCount++] = data;
}

void Reallocate(tArr* _pArr) //재할당 함수
{
	// 1. 현재 공간보다 2배 늘리기 + 새로운 공간의 주소를 지역변수로 받아놓기
	int* pNew = (int*)malloc(sizeof(int) * 2 * _pArr->iMaxCount);

	// 2. 원래 데이터 옮기기
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}
	// 3. 기존 공간 메모리 해제해주기
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키게 하기
	_pArr->pInt = pNew;


	// 5. maxcount 변경하기
	_pArr->iMaxCount *= 2;

}
