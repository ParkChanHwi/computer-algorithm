#pragma once

typedef struct _tabArr 
{

	int* pInt; // �������� �����͸� �����ϴ� �� �޸� ���� (�ּҰ�) int �����͸� ����� �����ϴ� ����ü
	int iCount; // �����Ͱ� �� �� ���Դ��� ���� üũ (���� �����Ͱ� ��� ��ġ�� ������ ���ϴ� ����)
	int iMaxCount; // �����Ͱ� �� ���� ��� ������ ������ �ø��� ���� üũ�ϴ� ����

}tArr;

// �ʱ�ȭ �Լ�. ù �����迭�� ��� ������ �޸𸮸� �Ҵ����� �ʱ�ȭ ��ȯ�� �ǹ� x
void InitArr(tArr* _pArr); // �Լ� ���� �ٷ� ����� ����Ű ctrl + "+" + "."

// ������ �߰� �Լ�
void Add_Data(tArr* _pArr, int data);

// �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);

// ���� ���Ҵ� +  �߰������� ���� ���Ҵ��� �����Ͱ� �� �� ��쿡�� ����� �� �־�� �ϴµ� ���ο��� ȣ���� �����ϹǷ� ��������� �������� �ʴ´�.
// void Reallocate(tArr* _pArr);