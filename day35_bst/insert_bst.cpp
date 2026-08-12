#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

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

void bst_insert(Tree **root,int data) {
if (*root == NULL) {
*root = create_node(data);
return;
}
if (data < (*root)->data) {
bst_insert(&(*root)->left,data);
} else if (data > (*root)->data) {
bst_insert(&(*root)->right,data);
} else {
bst_insert(&(*root)->left,data);
}
}

void inorder(Tree *root) {
if (root == NULL) return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

void destroy(Tree *root) {
if (root == NULL) return;
Tree *temp = root;
destroy(root->left);
destroy(root->right);
free(temp);
temp = NULL;
}

int main() {
vector<int> v = {5,3,7,2,4,6,8};
Tree *root = NULL;
for (int x : v) {
bst_insert(&root,x);
}
inorder(root);
cout << endl;
destroy(root);
return 0;
}
