#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
struct Node *next;
}Node;
int main() {
Node *first = (Node *)malloc(sizeof(Node));
Node *second = (Node *)malloc(sizeof(Node));

if (first == NULL ||second == NULL) {
printf("内存分配失败!\n");
return 1;
}

first->data = 10;
first->next = second;

second->data = 20;
second->next = NULL;

Node *current = first;
while (current != NULL) {
printf("%d ->",current->data);
current = current->next;
}
printf("NULL\n");
free(first);
free(second);
return 0;
}
