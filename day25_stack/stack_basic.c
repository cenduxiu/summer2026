#include <stdio.h>
#include <stdbool.h>

#define MAX 100

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
if(isFull(s)) {
printf("栈已满!\n");
return;
}
s->data[++(s->top)] = value;
}

int pop(Stack *s) {
if (isEmpty(s)) {
printf("栈为空!\n");
return -1;
}
return s->data[(s->top)--];
}

int peek(Stack *s) {
if (isEmpty(s)) {
printf("栈为空!\n");
return -1;
}
return s->data[s->top];
}

int main() {
Stack s;
init(&s);

for (int i = 1;i < 6;i++) {
push(&s,i);
}

printf("出栈两次: %d %d\n",pop(&s),pop(&s));
printf("当前栈顶: %d\n",peek(&s));

printf("剩余元素出栈: ");
while (!isEmpty(&s)) {
printf("%d ",pop(&s));
}
printf("\n");
return 0;
}


