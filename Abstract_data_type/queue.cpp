#include <stdio.h>
#include <iostream>

typedef int element;

typedef struct TagNode {
	element Data;
}Node;


typedef struct Tagqueue {
	int capacity; // ť�� �뷮
	int front; 
	int rear;

	Node* Nodes;
}CircleQueue;

// ť �Լ��� �⺻ 1. ����  2. ����  3. ����  4. ����  5. Ǯ

void CreateQueue(CircleQueue** Queue, int capacity); // ����

void Enqueue(CircleQueue* Queue, element data); // ����

void FreeQueue(CircleQueue* queue); // �޸� ��ȯ

element Dequeue(CircleQueue* Queue); // ����

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

	if (Queue->rear == Queue->capacity) {  // �Ĵ��� �迭�� ���� ����, rear�� position�� 0���� ����
		position = Queue->rear;
		Queue->rear = 0;
	}

	else { // �Ĵ��� ���� �迭�� ���� �ƴϹǷ� ���� �Ĵ��� ��ġ�� ������ ���� �� �Ĵ��� �ϳ� ������Ŵ
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
	return (Queue->front == Queue->rear); // �����̸� 1 �ƴҰ�� 0
}

int IsFull(CircleQueue* Queue) {
	
	if (Queue->front < Queue->rear)
		return (Queue->rear - Queue->front) == Queue->capacity;


	else
		return (Queue->rear + 1) == Queue->front;
}