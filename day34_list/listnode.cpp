#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node {
int data;
struct Node *next;
} Node;

Node *create_node(int data) {
Node *node = (Node *)malloc(sizeof(Node));
if (node == NULL) return NULL;
node->data = data;
node->next = NULL;
return node;
}

void insert_head(Node **head,int data) {
Node *node = create_node(data);
if (node == NULL) return;
node->next = *head;
*head = node;
}

Node *list_node(Node *head) {
Node *fast = head,*slow = head;
while (fast != NULL&&fast->next != NULL) {
slow = slow->next;
fast = fast->next->next;
}
return slow;
}

void free_node(Node *head) {
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

for (int i = 5;i > 0;i--) {
insert_head(&head,i);
}
Node *a = list_node(head);
cout << a->data << endl;
free_node(head);

Node *head1 = NULL;
for (int i = 4;i > 0;i--) {
insert_head(&head1,i);
}
Node *b = list_node(head1);
cout << b->data << endl;
free_node(head1);

return 0;
}
