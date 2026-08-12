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
Node *new_node = create_node(data);
if (new_node == NULL) return;
new_node->next = *head;
*head = new_node;
}

Node *reverse(Node *head) {
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

void cout_node(Node *head) {
Node *current = head;
while (current != NULL) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
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
cout_node(head);

Node *new_head = reverse(head);
cout_node(new_head);

return 0;
}
