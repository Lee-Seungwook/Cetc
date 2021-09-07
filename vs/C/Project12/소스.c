#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// 전위 순회
void preorder(TreeNode *root) {
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder((TreeNode*)root->left);
	preorder((TreeNode*)root->right);
}

// 중위 순회
void inorder(TreeNode *root) {
	if (root == NULL)
		return;
	inorder((TreeNode*)root->left);
	printf("%d ", root->data);
	inorder((TreeNode*)root->right);
}

// 후위 순회
void postorder(TreeNode *root) {
	if (root == NULL)
		return;
	postorder((TreeNode*)root->left);
	postorder((TreeNode*)root->right);
	printf("%d ", root->data);
}


TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 2, &n1, NULL };
TreeNode n3 = { 3, NULL, NULL };
TreeNode n4 = { 4, NULL, NULL };
TreeNode n5 = { 5, &n3, &n4 };
TreeNode n6 = { 6, &n2, &n5 };
TreeNode n7 = { 7, NULL, NULL };
TreeNode n8 = { 8, &n6, &n7 };
TreeNode n9 = { 9, NULL, &n8 };
TreeNode *root = &n9;


int main() {
	/*TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n6 = (TreeNode*)malloc(sizeof(TreeNode));
	n7 = (TreeNode*)malloc(sizeof(TreeNode));
	n8 = (TreeNode*)malloc(sizeof(TreeNode));
	n9 = (TreeNode*)malloc(sizeof(TreeNode));

	 n1->data = 10;
   n1->left = (struct TreeNode*) n2;
   n1->right = (struct TreeNode*) n3;

   n2->data = 20;
   n2->left = (struct TreeNode*) n4;
   n2->right = (struct TreeNode*) n5;;

   n3->data = 30;
   n3->left = (struct TreeNode*) n6;
   n3->right = (struct TreeNode*) n7;

   n4->data = 40;
   n4->left = (struct TreeNode*) n8;
   n4->right = (struct TreeNode*) n9;

   n5->data = 50;
   n5->left = NULL;
   n5->right = NULL;

   n6->data = 60;
   n6->left = NULL;
   n6->right = NULL;

   n7->data = 70;
   n7->left = NULL;
   n7->right = NULL;

   n8->data = 80;
   n8->left = NULL;
   n8->right = NULL;

   n9->data = 90;
   n9->left = NULL;
   n9->right = NULL;*/


	printf("중위순회(inorder) : ");
	inorder(root);
	printf("\n전위순회(preorder) : ");
	preorder(root);
	printf("\n후위순회(postorder) : ");
	postorder(root);
	printf("\n");



	/*n1->data = 10;
	n1->left = (struct TreeNode*) n2;
	n1->right = (struct TreeNode*) n3;

	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;

	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;*/

	return 0;
}

/*typedef struct treenode {
	int data;
	struct treenode *left, *right;
} treenode;

treenode n1 = { 1, NULL, NULL };
treenode n2 = { 4, &n1, NULL };
treenode n3 = { 16, NULL, NULL };
treenode n4 = { 25, NULL, NULL };
treenode n5 = { 20, &n3, &n4 };
treenode n6 = { 15, &n2, &n5 };
treenode *root = &n6;*/