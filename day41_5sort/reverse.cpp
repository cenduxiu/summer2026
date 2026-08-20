#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node{
int data;
struct node *next;
}node;

node *create_node(int data) {
node *new_node = (node *)malloc(sizeof(node));
if (new_node == NULL) return NULL;
new_node->data = data;
new_node->next = NULL;
return new_node;
}

void head_insert(node **head,int data) {
node *new_node = create_node(data);
if (new_node == NULL) return;
new_node->next = *head;
*head = new_node;
}

node *reverse(node *head) {
if (head == NULL||head->next == NULL) return head;
node *new_head = reverse(head->next);
head->next->next = head;
head->next = NULL;
return new_head;
}

void print(node *head) {
if (head == NULL) return;
node *current = head;
while (current != NULL) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}

void destroy(node *head) {
if (head == NULL) return;
node *current = head;
while (current != NULL) {
node *temp = current;
current = current->next;
free(temp);
temp = NULL;
}
}

int main() {
int data[] = {1,2,3,4,5,6};
int n = sizeof(data) / sizeof(int);
node *head = NULL;
for (int i = 0;i < n;i++) {
head_insert(&head,data[i]);
}
node *new_head = reverse(head);
print(new_head);
destroy(new_head);
return 0;
}
