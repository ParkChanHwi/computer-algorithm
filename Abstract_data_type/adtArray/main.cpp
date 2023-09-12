#include <iostream>
#include "Arr.h"
int main()
{
	tArr s; // 배열 객체 이 객체에게 데이터를 주면 힙 메모리 영역에 저장
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