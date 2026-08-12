#include <stdio.h>
#include <stdbool.h>

#define MAX 6

typedef struct{
int data[MAX];
int front;
int rear;
}Queue;

void init(Queue *q) {
q->front = 0;
q->rear = 0;
}

bool isEmpty(Queue *q) {
return q->front == q->rear;
}

bool isFull(Queue *q) {
return q->front == (q->rear + 1) % MAX;
}

int size(Queue *q) {
return (q->rear - q->front + MAX) % MAX;
}

void enqueue(Queue *q,int value) {
if (isFull(q)) return;
q->data[q->rear] = value;
q->rear = (q->rear + 1) % MAX;
printf("入队%d,当前front = %d,rear = %d,size = %d\n",value,q->front,q->rear,size(q));
}

int dequeue(Queue *q) {
if (isEmpty(q)) return -1;
int value = q->data[q->front];
q->front = (q->front + 1) % MAX;
printf("出队%d,当前front = %d,rear = %d,size = %d\n",value,q->front,q->rear,size(q));
return value;
}

int peekFront(Queue *q) {
if (isEmpty(q)) return -1;
return q->data[q->front];
}

void printQueue(Queue *q) {
if (isEmpty(q)) return;
printf("队列内容:");
int i = q->front;
while (i != q->rear) {
printf("%d",q->data[i]);
i = (i + 1) % MAX;
}
printf("\n");
}

int main() {
Queue q;
init(&q);

printf("===循环队列测试===\n");
printf("队列容量:%d(最多存%d个元素)\n\n",MAX,MAX - 1);

printf("---入队---\n");
for (int i = 1;i < 6;i++) {
enqueue(&q,i);
}
printQueue(&q);
printf("\n---出队两次---\n");
dequeue(&q);
dequeue(&q);
printQueue(&q);

printf("\n---入队6 7---\n");
enqueue(&q,6);
enqueue(&q,7);
printQueue(&q);

printf("\n队头元素: %d\n",peekFront(&q));

printf("\n---全部出队---\n");
while (!isEmpty(&q)) {
dequeue(&q);
}
printf("\n---测试队列满---\n");
for (int i = 1;i < 7;i++) {
enqueue(&q,i * 10);
}

return 0;
}

