#include <stdio.h>
#include <stdbool.h>

#define MAX 32

typedef struct {
int data[MAX];
int top;
}Stack;

void init(Stack *s) {
s->top = -1;
}

bool isEmpty(Stack *s) {
return s->top == -1;
}

bool isFull(Stack *s) {
return s->top == MAX - 1;
}

void push(Stack *s,int value) {
if (isFull(s)) return;
s->data[++(s->top)] = value;
}

int pop(Stack *s) {
if (isEmpty(s)) return -1;
return s->data[(s->top)--];
}

void decimalToBinary(int n) {
Stack s;
init(&s);

if (!n) {
printf("0\n");
return;
}
while (n > 0) {
push(&s,n % 2);
n /= 2;
}
printf("二进制：");
while (!isEmpty(&s)) {
printf("%d",pop(&s));
}
printf("\n");
}
int main() {
int n;
printf("请输入一个十进制整数:");
scanf("%d",&n);
decimalToBinary(n);
return 0;
}
