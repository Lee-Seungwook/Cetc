
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
		printf("메모리 할딩 에러.\n"); exit(1);
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
		if (p->data == x) return p;  // 탐색 성공
		p = p->link;
	}
	return p;  // 탐색 실패일 경우 NULL 반환
}

ListNode *InserNode(ListNode *x, int value) //삽입
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

void deleteNode(ListNode *x, ListNode*y) //삭제
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
	printf("-----------------50이 20앞에 삽입됨\n");

	pre = search(head, 40);
	remove = pre->link;
	deleteNode(remove, pre);
	display(head);
	printf("-----------------40앞의 30이 삭제됨\n");

	pre = search(head, 50);
	remove = pre->link;
	deleteNode(remove, pre);
	display(head);
	printf("-----------------맨 앞의 10이 삭제됨\n");


	deleteNode(remove, NULL);
	display(head);
	printf("-----------------맨 뒤의 40 삭제됨");

	return 0;
}