#include <iostream>
#include <string.h>
#define MAX_LEN 2000000

typedef struct CQ_Queue {
  int *Arr;
  int Rear;
  int Front;
} CQ;

CQ *createQue() {
  CQ *cqueue = (CQ *)malloc(sizeof(CQ));
  if (cqueue != NULL) {
    cqueue->Arr = (int *)malloc(sizeof(int) * MAX_LEN);
    if (cqueue->Arr == NULL)
      free(cqueue);
    return NULL;
  } else {
    cqueue->Front = cqueue->Rear = 0;
  }
  return cqueue;
}
int Empty(CQ *queue);

void push(CQ *Queue, int data);

int pop(CQ *Queue);

int size(CQ *Queue);

int Qfront(CQ *Queue);

int Qback(CQ *Queue);

int main() {
  CQ *cQueue = createQue();
  int c_num = 0;
  char command[6];
  scanf("%d", &c_num);

  for (int i = 0; i < c_num; i++) {
    scanf("%s", command);
    if (strcmp("push", command) == 0) {
      int x = 0;
      scanf("%d", &x);
      push(cQueue, x);
    } else if (strcmp("pop", command) == 0)
      printf("%d\n", pop(cQueue));
  }
}
int Empty(CQ *queue) {
  if (queue->Front == queue->Rear) {
    return 1;
  } else
    return 0;
}

void push(CQ *Queue, int data) {
  int countRear = (Queue->Rear + 1) % MAX_LEN;
  if (Queue != NULL && countRear != Queue->Front) // queue Isfull?
  {
    Queue->Arr[Queue->Rear] = data;
    Queue->Rear = countRear;
  }

  else
    printf("Queue is Full");
}

int pop(CQ *Queue) {
  int Position = Queue->Front;

  if (Empty(Queue) == 1)
    return -1;

  else {
    Queue->Front++;
  }
  return Queue->Arr[Position];
}

int size(CQ *Queue) {

  return ((Queue->Rear - Queue->Front + 1) + MAX_LEN) % MAX_LEN;
}

int Qfront(CQ *Queue) {
  if (Empty(Queue) == 1)
    return -1;
  else {
    int Position = Queue->Front;
    return Queue->Arr[Position];
  }
}

int Qback(CQ *Queue) {
  if (Empty(Queue) == 1)
    return -1;
  else {
    int Position = Queue->Rear - 1;
    return Queue->Arr[Position];
  }
}