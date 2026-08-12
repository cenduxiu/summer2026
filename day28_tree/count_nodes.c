#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
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

int countnodes(TreeNode *root) {
if (root == NULL) return 0;
int left = countnodes(root->left);
int right = countnodes(root->right);
return 1 + left + right;
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
root->right->right = createnode(6);
printf("节点总数: %d\n",countnodes(root));
destroyTree(root);
return 0;
}
