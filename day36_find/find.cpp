#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct Tree{
int data;
struct Tree *left;
struct Tree *right;
} Tree;

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
if (data < root->data) 
root->left = bst_insert(root->left,data);
else if (data > root->data) 
root->right = bst_insert(root->right,data);
return root;
}

void inorder(Tree *root) {
if (root == NULL) return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

Tree *find(Tree *root,int target) {
if (root == NULL) return NULL;
if (target == root->data) return root;
else if (target > root->data) 
return find(root->right,target);
else return find(root->left,target);
}

int height(Tree *root) {
if (root == NULL) return 0;
int left = height(root->left);
int right = height(root->right);
return 1 + (left > right ? left : right);
}

int number(Tree *root) {
if (root == NULL) return 0;
return 1 + number(root->left) + number(root->right);
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
Tree *root = NULL;
vector<int> v(7);
v = {5,3,7,2,4,6,8};
for (int x : v) 
root = bst_insert(root,x);
inorder(root);
cout << endl;

int a = height(root);
int b = number(root);
cout << "高度:" << a << endl << "节点数量:" << b << endl;
if (6 == find(root,6)->data)
cout << "找到:6" << endl;
if (NULL == find(root,9)) 
cout << "未找到:9" << endl;
destroy(root);
return 0;
} 
