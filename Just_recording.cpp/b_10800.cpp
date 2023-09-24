#include <iostream>
#define MAX_SIZE 200001

typedef struct BALL {
	int color;
	int size;
	int score;
}BALL;

int main(void) {
	int n = 0;
	BALL* b;
	b = (BALL*)malloc(MAX_SIZE*sizeof(BALL));

	scanf_s("%d", &n);

	// 초기화
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &b[i].color);
		scanf_s("%d", &b[i].size);
		b[i].score = 0;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i].color != b[j].color) {
				if (b[i].size > b[j].size) {
					b[i].score += b[j].size;
				}
				
			}
		}
		printf("%d\n", b[i].score);
	}






	free(b);
} // 컬러볼 문제 시간복잡도 때문에 정렬 이용해서 다시 풀기
