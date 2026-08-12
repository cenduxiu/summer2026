#include <stdio.h>
#include <stdlib.h>

#define S StackNode

typedef struct S{
int data;
struct S *next;
}S;

void push(S **top,int data) {
S *new_node = (S *)malloc(sizeof(S));
if (new_node == NULL) return;
new_node->data = data;
new_node->next = *top;
*top = new_node;
}
int pop(S **top) {
if (top == NULL) return -1;
S *temp = *top;
int data = temp->data;
*top = (*top)->next;
free(temp);
temp = NULL;
return data;
}

void freeStack(S *top) {
while (top != NULL) {
S *temp = top;
top = top->next;
free(temp);
temp = NULL;
}
}

void decimalToBinary(int n) {
S *top = NULL;

while (n > 0) {
push(&top,n % 2);
n /= 2;
}
printf("十进制%d的二进制: ",n);
while (top != NULL) {
printf("%d",pop(&top));
}
printf("\n");
freeStack(top);
}

int main() {
int num;

printf("请输入一个十进制整数:");
scanf("%d",&num);

decimalToBinary(num);

return 0;
}
