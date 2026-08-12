#include <stdio.h>
#include <stdlib.h>

typedef struct{
int data;
struct Node *next;
}Node;

int main() {
Node *node = (Node *)malloc(sizeof(Node));
if (node == NULL) {
printf("内存分配失败!\n");
return 1;
}

node->data = 42;
node->next = NULL;

printf("节点数据: %d\nnext指针: %p\n节点地址: %p\n",node->data,(void *)node->next,(void *)node);
free(node);

return 0;
}

