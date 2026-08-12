#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

Node *create_node(int data) {
Node *new_node = (Node *)malloc(sizeof(Node));
if (new_node == NULL)return NULL;
new_node->data = data;
new_node->next = NULL;
return new_node;
}

void insert_sorted(Node **head,int data) {
Node *new_node = create_node(data);
if (*head == NULL ||data < (*head)->data) {
new_node->next = *head;
*head = new_node;
return;
}
Node *current = *head;
while (current->next != NULL&&current->next->data < data) {
current = current->next;
}
new_node->next = current->next;
current->next = new_node;
}

int delete_value(Node **head,int value) {
if (*head == NULL)return 0;
if ((*head)->data == value) {
Node *temp = *head;
*head = (*head)->next;
free(temp);
return 1;
}
Node *current = *head;
while (current->next != NULL&&current->next->data != value) {
current = current->next;
}
if (current->next == NULL)return 0;
Node *temp = current->next;
current->next = temp->next;
free(temp);
return 1;
}

void print_list(Node *head) {
Node *current = head;
while (current != NULL) {
printf("%d->",current->data);
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
temp = NULL;
}
}

int main() {
int value[] = {5,3,8,1,9};
Node *head = NULL;
for (int i  = 0;i < 5;i++) {
insert_sorted(&head,value[i]);
print_list(head);
}

for (int i = 0;i < 5;i++) {
if (delete_value(&head,value[i])) {
printf("删除成功");
print_list(head);
} else {
printf("没找到");
}
}
if(!delete_value(&head,100)) {
printf("没找到");
}
free_list(head);

return 0;
}
