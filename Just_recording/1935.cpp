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
	int operand_num = 0; // �ǿ����� ����
	Stack s;
	char posfix_notation[10000] = "init";
	int operand[27];
	int num_list[27];
	InitStack(&s);
	int index = 0;
	double cal1, cal2 = 0;
	scanf("%d", &operand_num); // �ǿ����� ���� �Է�
	scanf("%s", posfix_notation); // �������� �Է�
	
	int length = strlen(posfix_notation);

	for (int i = 0; i < operand_num; i++) {
		scanf("%d", &operand[i]); 
	}

	for (int i = 0; i < length; i++) {
		

		

			if (posfix_notation[i] >= 'A' && posfix_notation[i] <= 'Z') {
				
				Stackpush(&s, operand[posfix_notation[i] - 'A']);  // �ٽ� ������ �κ� ������ index��  operand[index]�� �ٷ� �Է��ϴ� ������ �߾��µ� A�� 3�� �ԷµǴ� ��� �ٷ� ����
				// A,B,C,D,E,F,G~,Z,�� �� �����ϰ� ���� �־���� �ϳ�? ������ ���� ���߿� �޾ƿ��� A~Z�� ���ڿ��� ����Ǿ��־ �ָ�����
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