#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

Node *create_node(int data) {
Node *new_node = (Node *)malloc(sizeof(Node));
if (new_node == NULL) {
printf("内存分配失败!\n");
return NULL;
}
new_node->data = data;
new_node->next = NULL;
return new_node;
}

void insert_at_head(Node **head,int data) {
Node *new_node = create_node(data);
if (new_node == NULL) return;
new_node->next = *head;
*head = new_node;
}

void insert_at_tail(Node **head,int data) {
Node *new_node = create_node(data);
if (new_node == NULL)return;
if (*head == NULL) {
*head = new_node;
return;
}
Node *current = *head;
while (current->next != NULL) {
current = current->next;
}
current->next = new_node;
}

void print_list(Node *head) {
Node *current = head;
while (current != NULL) {
printf("%d ->",current->data);
current = current->next;
}
printf("NULL\n");
}

void free_list(Node *head) {
Node *current = head;
while (current != NULL) {
Node *temp = current;
current = current->next;
free(temp);
}
}

int main() {
Node *list1 = NULL;
printf("头插法插入1到5: \n");
for (int i = 1;i <= 5;i++) {
insert_at_head(&list1,i);
}
print_list(list1);
free_list(list1);
Node *list2 = NULL;
printf("\n尾插法插入1到5:\n");
for (int i = 1;i <= 5;i++) {
insert_at_tail(&list2,i);
}
print_list(list2);
free_list(list2);
return 0;
}

