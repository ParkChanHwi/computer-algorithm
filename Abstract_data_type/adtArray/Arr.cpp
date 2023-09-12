#include "Arr.h"
#include<stdlib.h>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // ó���� �޸� ���� 8����Ʈ ��ŭ �Ҵ� (int�ڷ��� 2�� ���� ����)
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;

}

void ReleaseArr(tArr* _pArr) // �޸� ����
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Add_Data(tArr* _pArr, int data) // ������ �߰�
{
	if (_pArr->iMaxCount <= _pArr->iCount) {

		Reallocate(_pArr); // ���Ҵ�
	}

	_pArr->pInt[_pArr->iCount++] = data;
}

void Reallocate(tArr* _pArr) //���Ҵ� �Լ�
{
	// 1. ���� �������� 2�� �ø��� + ���ο� ������ �ּҸ� ���������� �޾Ƴ���
	int* pNew = (int*)malloc(sizeof(int) * 2 * _pArr->iMaxCount);

	// 2. ���� ������ �ű��
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}
	// 3. ���� ���� �޸� �������ֱ�
	free(_pArr->pInt);

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �ϱ�
	_pArr->pInt = pNew;


	// 5. maxcount �����ϱ�
	_pArr->iMaxCount *= 2;

}
