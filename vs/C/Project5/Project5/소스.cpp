
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct ListNode {
	int data;
	struct ListNode *link;
}ListNode;

ListNode *head;

ListNode  *getNode() {
	ListNode *temp;

	temp = (ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL) {
		printf("�޸� �ҵ� ����.\n"); exit(1);
	}

	return temp;
}




void display(ListNode *head)
{
	while (head != NULL) {
		printf("%d->", head->data);
		head = head->link;
	}
	printf("\n");
}

ListNode  *list_Create(int value)
{
	ListNode *temp;
	temp = getNode();
	temp->data = value;

	if (head == NULL)
		temp->link = NULL;
	else
		temp->link = head;

	head = temp;

	return head;
}




ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p;  // Ž�� ����
		p = p->link;
	}
	return p;  // Ž�� ������ ��� NULL ��ȯ
}

ListNode *InserNode(ListNode *x, int value) //����
{
	ListNode *temp;
	temp = getNode();
	if (temp == NULL)
		exit(1);
	else if (x == NULL)
	{
		temp->data = value;
		temp->link = x;
		x = temp;
	}
	else
	{
		temp->data = value;
		temp->link = x->link;
		x->link = temp;
	}
	return x;
}

void deleteNode(ListNode *x, ListNode*y) //����
{
	if (y == NULL)
	{
		x = head;
		head = x->link;
	}
	else
		y->link = x->link;

	free(x);
}

int main(void)
{
	ListNode *pre, *remove = NULL;

	list_Create(10);
	display(head);

	list_Create(20);
	display(head);

	list_Create(30);
	display(head);

	list_Create(40);
	display(head);

	pre = search(head, 20);
	InserNode(pre, 50);
	display(head);
	printf("-----------------50�� 20�տ� ���Ե�\n");

	pre = search(head, 40);
	remove = pre->link;
	deleteNode(remove, pre);
	display(head);
	printf("-----------------40���� 30�� ������\n");

	pre = search(head, 50);
	remove = pre->link;
	deleteNode(remove, pre);
	display(head);
	printf("-----------------�� ���� 10�� ������\n");


	deleteNode(remove, NULL);
	display(head);
	printf("-----------------�� ���� 40 ������");

	return 0;
}