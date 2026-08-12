#include <stdio.h>
#include <stdlib.h>

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
if (*top == NULL) return -1;
StackNode *temp = *top;
int data = temp->data;
*top = (*top)->next;
free(temp);
temp = NULL;
return data;
}

int size(StackNode *top) {
int count = 0;
while (top != NULL) {
count++;
top = top->next;
}
return count;
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
printf("初始大小: %d\n",size(top));
for (int i = 10;i < 40;i += 10) {
push(&top,i);
}
printf("入栈3个大小: %d\n",size(top));
pop(&top);
printf("出栈1个大小: %d\n",size(top));
freeStack(top);
return 0;
}
