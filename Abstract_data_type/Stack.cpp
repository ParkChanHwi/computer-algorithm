#include <iostream>
#include<stdio.h>
using namespace std;

typedef int element;


typedef struct StackNode {
	element data;
	struct StackNode* link	;
}StackNode;

typedef struct {
	StackNode * top;
	int size;
}Stack;


int isStackEmpty(Stack* s);
void InitStack(Stack * s);
void Stackpush(Stack* s,element item);
element pop(Stack* s);
element peek(Stack* s);

int main() {
	Stack s;
	InitStack(&s);
	int total_command = 0;// 총 입력할 명령
	int command; // 명령
	int p_Item = 0;
	int is = 0;
	scanf_s("%d", &total_command);

	for (int i = 0; i < total_command; i++) {
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			scanf_s("%d", &p_Item);
			Stackpush(&s,p_Item);
			break;
		case 2:

			is = isStackEmpty(&s) ? p_Item = -1 : p_Item = pop(&s);
				
			printf("%d\n", p_Item);
			
			break;
		case 3:
			printf("%d\n", s.size);
			 break;
		case 4:
			is = isStackEmpty(&s);
			printf("%d\n", is);
			break;
		case 5:
			is = isStackEmpty(&s) ? p_Item = -1 : p_Item = peek(&s);
			is = isStackEmpty(&s);
			printf("%d\n", p_Item);
			break;
		}
	}

}




int isStackEmpty(Stack* s) {
	if (s->top == NULL) return 1;
	else return 0;
}

void InitStack(Stack * s) {
	s->top = NULL;
	s->size = 0; 
}

void Stackpush(Stack *s ,element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	s->size++;
	temp->link = s->top;
	s->top = temp;
}

element pop(Stack * s) {
	element item;
	StackNode* temp = s->top;

	if (isStackEmpty(s)) {
		printf("Stack is Empty\n");
	}
	else {
		item = temp->data;
		s->top = temp->link;
		s->size--;
		free(temp);
		return item;
	}
}

element peek(Stack* s) {

	if (isStackEmpty(s)) {
	printf("Stack is Empty\n");
}
	else {
		return s->top->data;
	}

}

