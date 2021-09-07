#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

int d_size(TreeNode *root) {
	if (root->left == NULL && root->right == NULL)
		return root->data;
	int left = d_size((TreeNode*)root->left);
	int right = d_size((TreeNode*)root->right);
	return root->data + left + right;
}

int main() {
	TreeNode n5 = { 40, NULL, NULL }; //python
	TreeNode n4 = { 30, NULL, NULL }; //java
	TreeNode n3 = { 100, NULL, NULL }; //game
	TreeNode n2 = { 20, &n4, &n5 }; //Language
	TreeNode n1 = { 50, &n2, &n3 }; //D

	printf("D드라이브의 크기 : %dKByte\n", d_size(&n1));
	return 0;
}