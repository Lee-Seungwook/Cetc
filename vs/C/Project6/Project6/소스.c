#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct listnode {
	element data;
	struct listnode *link;
}listnode;

listnode *head;

//리스트의 항목 출력
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
	
	printf("%d->", p->data); //마지막 노드 출력

}

listnode*insert_first(listnode*head, element data)
{
	listnode*node = (listnode*)malloc(sizeof(listnode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	} //이 코드는 필수 코드 없으면 안됨!!
	else {
		node->link = head->link; //(1)
		head->link = node; //(2)
	}
	return head; //변경된 헤드 포인터를 반환한다.
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
	return head; //변경된 헤드 포인터를 반환한다.
}//원형 연결 리스트 테스트 프로그램

listnode *search(listnode *head, int x)
{
	listnode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p;  // 탐색 성공
		p = p->link;
	}
	return NULL;  // 탐색 실패일 경우 NULL 반환
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
	printf("삭제 리스트 출력: ");
	
	pre = search(head, 10);
	remove = pre->link;
	
	deletenode(remove, pre);
	print_list(head);
	
	return 0;
}