#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int left_thread;
	int right_thread;
} TreeNode;

TreeNode n1 = { 'A',NULL,NULL,1,1 };
TreeNode n2 = { 'B',NULL,NULL,1,1 };
TreeNode n3 = { 'C',&n1,&n2,0,0 };
TreeNode n4 = { 'D',NULL,NULL,1,1 };
TreeNode n5 = { 'E',NULL,NULL,1,1 };
TreeNode n6 = { 'F',&n4,&n5,0,0 };
TreeNode n7 = { 'G',&n3,&n6,0,0 };

TreeNode* insucc(TreeNode *tree)
{
	TreeNode*temp;
	temp = tree->right;
	if (!tree->right_thread)
		while (temp->left_thread != 1)
			temp = temp->left;
	return temp;
}


void thread_inorder(TreeNode *T)
{
	TreeNode*current_node;
	current_node = T;
	while (1) {
		current_node = insucc(current_node);
		if (current_node == T)break;
		printf("%3c", current_node->data);
	}
}



int main(void)
{
	TreeNode*T = (TreeNode*)malloc(sizeof(TreeNode));
	T->left = &n7;
	T->right = T;
	T->left_thread = 0;
	T->right_thread = 0;

	//스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	n5.right = T;

	n1.left = T;
	n2.left = &n3;
	n4.left = &n7;
	n5.left = &n5;

	//중위순회
	thread_inorder(T);
	printf("\n");
	return 0;
}