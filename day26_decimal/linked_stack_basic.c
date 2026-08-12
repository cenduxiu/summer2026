#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode{
int data;
struct StackNode *next;
}StackNode;

void push(StackNode **top,int data) {
StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
if (new_node == NULL) return;
new_node->data = data;
new_node->next = *top;
*top = new_node;
}

int pop(StackNode **top) {
if (*top == NULL) {
printf("栈为空!\n");
return -1;
}
StackNode *temp = *top;
*top = (*top)->next;
int data = temp->data;
free(temp);
return data;
}

int peek(StackNode *top) {
if (top == NULL) {
printf("栈为空!\n");
return -1;
}
return top->data;
}

bool isEmpty(StackNode *top) {
return top == NULL;
}

void freeStack(StackNode *top) {
while (top != NULL) {
StackNode *temp = top;
top = top->next;
free(temp);
temp = NULL;
}
}

int main() {
StackNode *top = NULL;
push(&top,10);
push(&top,20);
push(&top,30);

printf("出栈两次: %d %d\n",pop(&top),pop(&top));
printf("当前栈顶: %d\n",peek(top));

printf("剩余元素出栈: ");
while (!isEmpty(top)) {
printf("%d",pop(&top));
}
printf("\n");
freeStack(top);
return 0;
}
