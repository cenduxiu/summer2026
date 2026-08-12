#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
int data;
struct TreeNode *left;
struct TreeNode *right;
}TreeNode;

TreeNode *createnode(int data) {
TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
if (node == NULL) return NULL;
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}

void preorder(TreeNode *root) {
if (root == NULL) return;
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(TreeNode *root) {
if (root == NULL) return;
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
void postorder(TreeNode *root) {
if (root == NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d",root->data);
}

void destroyTree(TreeNode *root) {
if (root == NULL) return;
destroyTree(root->left);
destroyTree(root->right);
free(root);
}

int main() {
TreeNode *root = createnode(1);
root->left = createnode(2);
root->right = createnode(3);
root->left->left = createnode(4);
root->left->right = createnode(5);
root->left->left->left = createnode(7);
root->right->right = createnode(6);
printf("前序遍历:");
preorder(root);
printf("\n");

printf("中序遍历:");
inorder(root);
printf("\n");

printf("后序遍历:");
postorder(root);
printf("\n");
destroyTree(root);
return 0;
}
