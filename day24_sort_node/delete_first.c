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
}
}

void delete_head(Node **head) {
if (*head == NULL) {
printf("链表为空，无法删除!\n");
return;
}
Node *temp = *head;
*head = (*head)->next;
free(temp);
printf("头节点已删除\n");
}

int main() {
Node *head = NULL;
for (int i = 1;i <= 5;i++) {
insert_at_tail(&head,i);
}
print_list(head);

delete_head(&head);
print_list(head);

delete_head(&head);
print_list(head);

free_list(head);
return 0;
}
