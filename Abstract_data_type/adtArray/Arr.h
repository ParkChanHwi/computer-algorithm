#pragma once

typedef struct _tabArr 
{

	int* pInt; // 전달해준 데이터를 저장하는 힙 메모리 영역 (주소값) int 데이터를 멤버로 저장하는 구조체
	int iCount; // 데이터가 몇 개 들어왔는지 개수 체크 (다음 데이터가 어느 위치에 들어갈지를 정하는 변수)
	int iMaxCount; // 데이터가 꽉 차는 경우 데이터 영역을 늘리기 위해 체크하는 변수

}tArr;

// 초기화 함수. 첫 가변배열을 어느 정도의 메모리를 할당할지 초기화 반환값 의미 x
void InitArr(tArr* _pArr); // 함수 원형 바로 만드는 단축키 ctrl + "+" + "."

// 데이터 추가 함수
void Add_Data(tArr* _pArr, int data);

// 메모리 해제 함수
void ReleaseArr(tArr* _pArr);

// 공간 재할당 +  추가적으로 공간 재할당은 데이터가 꽉 찬 경우에만 사용할 수 있어야 하는데 메인에서 호출이 가능하므로 헤더에서는 명시하지 않는다.
// void Reallocate(tArr* _pArr);