#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct{
int data[MAX];
int front;
int rear;
int size;
}Queue;

void init(Queue *q) {
q->front = 0;
q->rear = 0;
q->size = 0;
}

bool isEmpty(Queue *q) {
return q->size == 0;
}

bool isFull(Queue *q) {
return q->size == MAX;
}

void enqueue(Queue *q,int value) {
if (isFull(q)) return;
q->data[q->rear] = value;
q->rear = (q->rear + 1) % MAX;
q->size++;
}

int dequeue(Queue *q) {
if (isEmpty(q)) return -1;
int value = q->data[q->front];
q->front = (q->front + 1) % MAX;
q->size--;
return value;
}

void print_q(Queue *q) {
printf("front = %d,rear = %d,size = %d\n",q->front,q->rear,q->size);
}

int main() {
Queue q;
init(&q);

printf("初始状态:");
print_q(&q);

for (int i = 1;i < 6;i++) {
enqueue(&q,i);
}
printf("\n入队后: ");
print_q(&q);

printf("\n出队两次: %d %d\n",dequeue(&q),dequeue(&q));
print_q(&q);

printf("\n入队 6 7:\n");
enqueue(&q,6);
enqueue(&q,7);
print_q(&q);

printf("全部出队: ");
while (!isEmpty(&q)) {
dequeue(&q);
}
print_q(&q);
printf("\n");
return 0;
}
