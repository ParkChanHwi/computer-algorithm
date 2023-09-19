#include <stdio.h>
#include <iostream>

typedef int element;

typedef struct TagNode {
	element Data;
}Node;


typedef struct Tagqueue {
	int capacity; // 큐의 용량
	int front; 
	int rear;

	Node* Nodes;
}CircleQueue;

// 큐 함수들 기본 1. 생성  2. 삭제  3. 삽입  4. 공백  5. 풀

void CreateQueue(CircleQueue** Queue, int capacity); // 생성

void Enqueue(CircleQueue* Queue, element data); // 삽입

void FreeQueue(CircleQueue* queue); // 메모리 반환

element Dequeue(CircleQueue* Queue); // 삭제

int IsEmpty(CircleQueue* Queue);

int IsFull(CircleQueue* Queue);


int main() {

	int i;

	CircleQueue* Queue;

	CreateQueue(&Queue, 10);

	Enqueue(Queue, 1);
	Enqueue(Queue, 2);
	Enqueue(Queue, 3);
	Enqueue(Queue, 4);

	for (i = 0; i < 3; i++) {
		printf("%d\n", Dequeue(Queue));
		printf("%d %d \n", Queue->front, Queue->rear);
	}


}

void CreateQueue(CircleQueue** Queue, int capacity) {
	(*Queue) = (CircleQueue*)malloc(sizeof(CircleQueue));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));
	(*Queue)->capacity = capacity;
	(*Queue)->front = 0;
	(*Queue)->rear = 0;
}

void Enqueue(CircleQueue* Queue, element data) {
	int position = 0;

	if (Queue->rear == Queue->capacity) {  // 후단이 배열의 끝에 도달, rear와 position을 0으로 지정
		position = Queue->rear;
		Queue->rear = 0;
	}

	else { // 후단이 아직 배열의 끝이 아니므로 원래 후단의 위치에 데이터 삽입 후 후단을 하나 증가시킴
		position = Queue->rear++;

		Queue->Nodes[position].Data = data;
	}
}

void FreeQueue(CircleQueue* queue) {
	free(queue->Nodes);
	free(queue);
}

element Dequeue(CircleQueue* Queue) {
	int Position = Queue->front;


	if (Queue->front == Queue->capacity) {
		Queue->front = 0;
	}

	else
		Queue->front++;

	return Queue->Nodes[Position].Data;
}

int IsEmpty(CircleQueue* Queue) {
	return (Queue->front == Queue->rear); // 공백이면 1 아닐경우 0
}

int IsFull(CircleQueue* Queue) {
	
	if (Queue->front < Queue->rear)
		return (Queue->rear - Queue->front) == Queue->capacity;


	else
		return (Queue->rear + 1) == Queue->front;
}