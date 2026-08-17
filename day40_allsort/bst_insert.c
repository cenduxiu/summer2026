#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
int data;
struct Tree *left;
struct Tree *right;
}Tree;

Tree *create_node(int data) {
Tree *node = (Tree *)malloc(sizeof(Tree));
if (node == NULL) return NULL;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}

Tree *bst_insert(Tree *root,int data) {
if (root == NULL) return create_node(data);
if (data <= root->data) 
root->left = bst_insert(root->left,data);
else root->right = bst_insert(root->right,data);
return root;
}

void inorder(Tree *root) {
if (root == NULL) return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}

void destroy(Tree *root) {
if (root == NULL) return;
destroy(root->left);
destroy(root->right);
Tree *temp = root;
free(temp);
temp = NULL;
}

int main() {
Tree *root = NULL;
int data[] = {3,6,4,6,8,2,7,2,1,9};
int n = sizeof(data) / sizeof(int);
for (int i = 0;i < n;i++) 
root = bst_insert(root,data[i]);
inorder(root);
printf("\n");
destroy(root);
return 0;
}
