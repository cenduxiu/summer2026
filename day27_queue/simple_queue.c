#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
int data[MAX];
int front;
int rear;
} Queue;

void init(Queue *q) {
q->front = 0;
q->rear = 0;
}

bool isEmpty(Queue *q) {
return q->front == q->rear;
}

bool isFull(Queue *q) {
return q->rear == MAX;
}

void enqueue(Queue *q,int value) {
if (isFull(q)) return;
q->data[q->rear] = value;
q->rear++;
}

int dequeue(Queue *q) {
if (isEmpty(q)) return -1;
int value = q->data[q->front];
 q->front++;
return value;
}

int main() {
Queue Q;
init(&Q);

for (int i = 1;i < 6;i++) {
enqueue(&Q,i);
}

printf("front = %d,rear = %d\n",Q.front,Q.rear);
printf("出队3次: %d %d %d\n",dequeue(&Q),dequeue(&Q),dequeue(&Q));
printf(" 剩余元素出队:");
while (!isEmpty(&Q)) {
printf("%d",dequeue(&Q));
}
printf("\n");
return 0;
}
