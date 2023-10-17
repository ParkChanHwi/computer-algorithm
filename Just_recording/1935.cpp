#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


typedef double element;




typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct Stack {
	int size;
	StackNode* top;
}Stack;


int isStackEmpty(Stack* s);
void InitStack(Stack* s);
void Stackpush(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);



int main() {
	int operand_num = 0; // 피연산자 개수
	Stack s;
	char posfix_notation[10000] = "init";
	int operand[27];
	int num_list[27];
	InitStack(&s);
	int index = 0;
	double cal1, cal2 = 0;
	scanf("%d", &operand_num); // 피연산자 개수 입력
	scanf("%s", posfix_notation); // 후위수식 입력
	
	int length = strlen(posfix_notation);

	for (int i = 0; i < operand_num; i++) {
		scanf("%d", &operand[i]); 
	}

	for (int i = 0; i < length; i++) {
		

		

			if (posfix_notation[i] >= 'A' && posfix_notation[i] <= 'Z') {
				
				Stackpush(&s, operand[posfix_notation[i] - 'A']);  // 핵심 막혔던 부분 원래는 index로  operand[index]를 바로 입력하는 식으로 했었는데 A만 3개 입력되는 경우 바로 오류
				// A,B,C,D,E,F,G~,Z,를 다 선언하고 값을 넣어줘야 하나? 했지만 값을 나중에 받아오고 A~Z도 문자열에 저장되어있어서 애매했음
				index++;
			}
			//ABC+
			else {
				switch (posfix_notation[i]) {
				case '+':
					cal2 = pop(&s);
					cal1 = pop(&s);
					Stackpush(&s, cal1 + cal2);
					break;

				case '-':
					cal2 = pop(&s);
					cal1 = pop(&s);
					Stackpush(&s, cal1 - cal2);
					break;

				case'/':
					cal2 = pop(&s);
					cal1 = pop(&s);
					Stackpush(&s, cal1 / cal2);
					break;

				case '*':
					cal2 = pop(&s);
					cal1 = pop(&s);
					Stackpush(&s, cal1 * cal2);
					
					break;

			


				default:
					printf("wrong expression\n");
					break;
				}

			
		}

	}

	
	printf("%.2f\n", pop(&s));

}


int isStackEmpty(Stack* s) {
	if (s->top == NULL) {
		return 1;
	}

	else return 0;
}


void InitStack(Stack* s) {
	s->size = 0;
	s->top = NULL;
}

void Stackpush(Stack* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	s->size++;
	temp->link = s->top;
	s->top = temp;
}

element pop(Stack* s) {
	element item;
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp = s->top;

	if (isStackEmpty(s)) {
		printf("Stack is Empty\n");
	}

	else{
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

	else return s->top->data;

}