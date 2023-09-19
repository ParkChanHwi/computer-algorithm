#include <iostream>
#include <string.h>
#define MAX_LEN 2000001

typedef struct CQ_Queue {
    int* Arr;
    int Rear;
    int Front;
} CQ;
int Empty(CQ* queue);
void push(CQ* Queue, int data);
int pop(CQ* Queue);
int size(CQ* Queue);
int Qfront(CQ* Queue);
int Qback(CQ* Queue);


int main() {
    CQ cQueue;
    cQueue.Front = 0;
    cQueue.Rear = 0;
    cQueue.Arr = (int*)malloc(sizeof(int) * MAX_LEN);
    int c_num = 0;
    char command[6];
    scanf("%d", &c_num);

    for (int i = 0; i < c_num; i++) {
        scanf("%s", command);
        if (strcmp("push", command) == 0) {
            int x = 0;
            scanf("%d", &x);
            push(&cQueue, x);
        }
        else if (strcmp("pop", command) == 0)
            printf("%d\n", pop(&cQueue));

        else if (strcmp("size", command)==0)
            printf("%d\n", size(&cQueue)-1);
        else if (strcmp("empty", command) == 0)
            printf("%d\n", Empty(&cQueue));

        else if (strcmp("front", command) == 0)
            printf("%d\n", Qfront(&cQueue));

        else if (strcmp("back", command) == 0)
            printf("%d\n", Qback(&cQueue));
    }
}

//여기부터 함수
int Empty(CQ* queue) {
    if (queue->Front == queue->Rear) {
        return 1;
    }
    else
        return 0;
}

void push(CQ* Queue, int data) {
    int countRear = (Queue->Rear + 1) % MAX_LEN;
    if (Queue != NULL && countRear != Queue->Front) // queue Isfull?
    {
        Queue->Arr[Queue->Rear] = data;
        Queue->Rear = countRear;
    }

    else
        printf("Queue is Full");
}

int pop(CQ* Queue) {
    int Position = Queue->Front;

    if (Empty(Queue) == 1)
        return -1;

    else {
        Queue->Front++;
    }
    return Queue->Arr[Position];
}

int size(CQ* Queue) {

    return ((Queue->Rear - Queue->Front + 1) + MAX_LEN) % MAX_LEN;
}

int Qfront(CQ* Queue) {
    if (Empty(Queue) == 1)
        return -1;
    else {
        int Position = Queue->Front;
        return Queue->Arr[Position];
    }
}

int Qback(CQ* Queue) {
    if (Empty(Queue) == 1)
        return -1;
    else {
        int Position = Queue->Rear - 1;
        return Queue->Arr[Position];
    }
}
