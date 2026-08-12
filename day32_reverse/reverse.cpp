#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node{
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

void insert_head(Node **head,int data) {
Node *new_node = create_node(data);
if (new_node == NULL) return;
new_node->next = *head;
*head = new_node;
}

Node *reverse(Node *head) {
if (head == NULL || head->next == NULL) return head;
Node *new_head = reverse(head->next);
head->next->next = head;
head->next = NULL;
return new_head;
}

void print_node(Node *head) {
Node *current = head;
while (current != NULL) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}

int main() {
Node *head = NULL;

for (int i = 5;i > 0;i--) {
insert_head(&head,i);
}
print_node(head);

Node *new_head = reverse(head);
print_node(new_head);

return 0;
}
