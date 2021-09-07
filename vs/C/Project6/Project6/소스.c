#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct listnode {
	element data;
	struct listnode *link;
}listnode;

listnode *head;

//����Ʈ�� �׸� ���
void print_list(listnode*head)
{
	listnode*p;

	if (head == NULL)return;
	p = head -> link;
	do {
		printf("%d->",p->data);
		p = p->link;
	} 
	
	while (p != head);
	
	printf("%d->", p->data); //������ ��� ���

}

listnode*insert_first(listnode*head, element data)
{
	listnode*node = (listnode*)malloc(sizeof(listnode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	} //�� �ڵ�� �ʼ� �ڵ� ������ �ȵ�!!
	else {
		node->link = head->link; //(1)
		head->link = node; //(2)
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

listnode*insert_last(listnode*head, element data)
{
	listnode*node = (listnode*)malloc(sizeof(listnode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; //(1)
		head->link = node;
		head = node;
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}//���� ���� ����Ʈ �׽�Ʈ ���α׷�

listnode *search(listnode *head, int x)
{
	listnode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p;  // Ž�� ����
		p = p->link;
	}
	return NULL;  // Ž�� ������ ��� NULL ��ȯ
}


void deletenode(listnode *x, listnode *y)
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


int main()
{
	listnode *pre, *remove = NULL;
	listnode *head = NULL;

	//list = {10 -> 20 -> 30 -> 40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("���� ����Ʈ ���: ");
	
	pre = search(head, 10);
	remove = pre->link;
	
	deletenode(remove, pre);
	print_list(head);
	
	return 0;
}