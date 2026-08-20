#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct tree{
int data;
struct tree *left;
struct tree *right;
}tree;

tree *create_tree(int data) {
tree *node = (tree *)malloc(sizeof(tree));
if (node == NULL) return NULL;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}

tree *bst_insert(tree *root,int data) {
if (root == NULL) return create_tree(data);
if (data >= root->data) 
root->right = bst_insert(root->right,data);
else root->left = bst_insert(root->left,data);
return root;
}

tree *find(tree *root,int target) {
if (root == NULL) return NULL;
if (root->data == target) return root;
else if (target < root->data) return find(root->left,target);
else return find(root->right,target);
}

void inorder(tree *root) {
if (root == NULL) return;
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

void destroy(tree *root) {
if (root == NULL) return;
destroy(root->left);
destroy(root->right);
tree *temp = root;
free(temp);
temp = NULL;
}

int main() {
vector<int> v = {5,2,4,6,7,8};
tree *root = NULL;
for (int x : v) root = bst_insert(root,x);
inorder(root);
cout << endl;
if (6 == find(root,6)->data) cout << "找到6" << endl;
if (NULL == find(root,9)) cout << "找不到9" << endl;
destroy(root);

return 0;
}
