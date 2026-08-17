#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

Node *create_node(int data) {
Node *node = (Node *)malloc(sizeof(Node));
if (node == NULL) return NULL;
node->data = data;
node->next = NULL;
return node;
}

void insert(Node **head,int data) {
Node *new_node = create_node(data);
if (new_node == NULL) return;
new_node->next = *head;
*head = new_node;
}

Node *reverse(Node *head) {
if (head == NULL|| head->next == NULL) return head;
Node *prev = NULL;
Node *current = head;
while (current != NULL) {
Node *temp = current->next;
current->next = prev;
prev = current;
current = temp;
}
return prev;
}

void print_node(Node *head) {
if (head == NULL) return;
printf("%d ",head->data);
print_node(head->next);
}

void freenode(Node *head) {
if (head == NULL) return;
Node *current = head;
while (current != NULL) {
Node *temp = current;
current = current->next;
free(temp);
temp = NULL;
}
}

int main() {
int data[] = {2,6,5,8,9,1};
int n = sizeof(data) / sizeof(int);
Node *head = NULL;
for (int i = 0;i < n;i++)
insert(&head,data[i]);
print_node(head);
printf("\n");

Node *new_head = reverse(head);
print_node(new_head);
printf("\n");

freenode(new_head);
return 0;
}
