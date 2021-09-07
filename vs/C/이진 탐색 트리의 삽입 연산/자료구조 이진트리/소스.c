#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;


treeNode* insertNode(treeNode *p, int x)
{
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n 같은키 있음 \n");

	return p;
}

void deleteNode(treeNode *root, element key)
{
	treeNode *a, *p, *b, *d;
	treeNode *c;

	a = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		a = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없음");
		return;
	}


	if ((p->left == NULL) && (p->right == NULL)) {
		if (a != NULL) {
			if (a->left == p) a->left = NULL;
			else a->right = NULL;
		}
		else root = NULL;
	}


	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) c = p->left;
		else c = p->right;

		if (a != NULL) {
			if (a->left == p) a->left = c;
			else a->right = c;
		}
		else root = c;
	}


	else {
		d = p;
		b = p->left;
		while (b->right != NULL) {
			d = b;
			b = b->right;
		}
		if (d->left == b) d->left = b->left;
		else d->right = b->left;
		p->key = b->key;
		p = b;
	}
	free(p);
}

treeNode* search(treeNode* root, int x)
{
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key)p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	return p;
}

void Inorder(treeNode* root)
{
	if (root) {
		Inorder(root->left);
		printf("%d ", root->key);
		Inorder(root->right);
	}
}

void menu()
{
	printf("\n 입력(1), 삭제(2), 탐색(3), 출력(4), 종료(5) : ");
}

int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char command;
	int key;

	root = insertNode(root, 10);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 90);
	insertNode(root, 60);
	insertNode(root, 50);
	insertNode(root, 40);

	do {
		menu();
		command = getchar(); getchar();

		switch (command) {
		case '4':
			Inorder(root); printf("\n");
			break;

		case '1':
			printf("key : ");
			scanf_s("%d", &key);
			getchar();
			insertNode(root, key);
			break;

		case '2':
			printf("key : ");
			scanf_s("%d", &key);
			getchar();
			deleteNode(root, key);
			break;

		case '3':
			printf("key : ");
			scanf_s("%d", &key);
			getchar();
			foundedNode = search(root, key);
			if (foundedNode != NULL)
				printf("\n이진 탐색 트리에서 %d 을 발견함 \n", foundedNode->key);
			else
				printf("\n이진 탐색 트리에서 %d 을 발견 못함 \n", foundedNode->key);
			break;
		}
	} while (command != '5');
}