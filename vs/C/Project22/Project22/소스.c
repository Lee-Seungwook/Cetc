#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
struct list {
	char name[10];
	int score;
	struct list *link;
};

void main()
{
	struct list *list1, *head, *pre, *next;
	head = NULL;
	int i;
	for (i = 0; i < 3; i++) {
		list1 = (struct list *)malloc(sizeof(struct list));
		scanf("%10s %3d\n", list1->name, &(list1->score));
		if (head == NULL)
			head = list1;
		else
			pre->link = list1;
		list1->link = NULL;
		pre = list1;
	}
	free(pre);
	for (next = head; next != NULL; next = next->link) {
		printf("%10s %d\n", next->name, next->score);
	}
	while (head != NULL) {
		next->link = head;
		printf("%s %d deleted \n", head->name, head->score);
		free(head);
		head = next;
	}
}
