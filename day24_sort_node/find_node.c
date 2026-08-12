#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
int data;
struct Node *next;
}Node;

Node *create_node(int data) {
Node *new_node = (Node *)malloc(sizeof(Node));
if (new_node == NULL) return NULL;
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

int find_value(Node *head,int value) {
Node *current = head;
while (current != NULL&&current->data != value) {
current = current->next;
}
if (current->data == value) {
return 1;
} else {
return 0;
}
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
Node *head = NULL;
for (int i = 10;i < 60;i += 10) {
insert_at_tail(&head,i);
}
int value[] = {10,20,30,40,50};
for (int i = 0;i < 5;i++) {
if (find_value(head,value[i])) {
printf("%d在链表中\n",value[i]);
} else {
printf("%d不在链表中\n",value[i]);
}
}
free_list(head);
return 0;
}
