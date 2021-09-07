#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct listnode {
	int data;
	struct listnode *link;
} listnode;

listnode *head;

listnode  *getnode() {
	listnode *temp;

	temp = (listnode *)malloc(sizeof(listnode));
	if (temp == NULL) {
		printf("메모리 할딩 에러.\n"); exit(1);
	}

	return temp;
}

/*listnode* create(int value)
{
	listnode *temp;
	temp = getnode();
	temp->data = value;

	if (head == NULL)
		temp->link = NULL;
	else
		temp->link = head;

	head = temp;

	return head;
}*/

/*listnode *getnode()
{
	listnode *temp;
	temp = (listnode *)malloc(sizeof(listnode));
	
	return temp;
}*/

listnode *create(int value)
{
	listnode *temp;
	temp = getnode();
	temp->data = value;
	
	if (head == NULL)
	{
		temp->link = NULL;
	}
	else 
	
		temp->link = head;
	
	head = temp;

	return head;
}

void display(listnode *head)
{
	while (head != NULL)
	{
		printf("%d->", head->data);
		head = head->link;
	}
	printf("\n");
}

int main()
{
	create(5);
	display(head);
	create(6);
	display(head);
	create(7);
	display(head);

	return 0;

}


