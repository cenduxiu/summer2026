#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
int data;
struct TreeNode *left;
struct TreeNode *right;
}TreeNode;

TreeNode *create_node(int data) {
TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
if (node == NULL) return NULL;
node->data= data;
node->left = NULL;
node->right = NULL;
return node;
}

void inorder(TreeNode *root) {
if (root == NULL) return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}

int count_node(TreeNode *root) {
if (root == NULL) return 0;
return 1 + count_node(root->left) + count_node(root->right);
}

int max_depth(TreeNode *root) {
if (root == NULL) return 0;
return 1 + (max_depth(root->left) > max_depth(root->right) ? max_depth(root->left) : max_depth(root->right));
}

void destroytree(TreeNode *root) {
if (root == NULL) return;
destroytree(root->left);
destroytree(root->right);
free(root);
}


int main() {
TreeNode *root = create_node(5);
root->left = create_node(2);
root->right = create_node(8);
root->left->left = create_node(7);

inorder(root);
printf("\n");
printf("%d\n",count_node(root));
printf("%d\n",max_depth(root));
destroytree(root);
return 0;
}
