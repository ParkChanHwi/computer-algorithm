#include <iostream>
#include "Arr.h"
int main()
{
	tArr s; // �迭 ��ü �� ��ü���� �����͸� �ָ� �� �޸� ������ ����
	InitArr(&s);
	
	for (int i = 0; i < 10; i++) {

		Add_Data(&s, i);

	}
	

	for (int i = 0; i < s.iCount; i++) {

		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);
	return 0;
}