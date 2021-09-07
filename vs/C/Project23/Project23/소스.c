#include <stdio.h>
#include <malloc.h>

struct seq_node{
	char data;
int key;
struct seq_node *link;
};

struct seq_node *seq_search(struct seq_node *list, int target)
{
	struct seq_node *ptr;
	ptr = list;
	while(target != ptr->key || ptr != NULL){ 
		if(target == ptr->key)
		break;
		else
		ptr = ptr->link;
	}
	return ptr;
}


struct seq_node *insert_first(struct seq_node *head, char data, int key)
{
	struct seq_node *p = (struct seq_node *)malloc(sizeof(struct seq_node));
	p->data = data;
	p->key = key;
	p->link = head;
	head = p;
	return head;
}

void print_list(struct seq_node *head)
{
	struct seq_node *p
		;
	for (p = head ; p != NULL ; p = p->link)
		printf("(%d, %c) ->", p->key, p->data);
	printf("NULL \n");
}

int main()
{
	struct seq_node *head = NULL;
	struct seq_node *searchednode;
	/*for (int i = 0; i < 5; i++) {
		int no = rand() % 5;
		char ch = 'A' + no;
		head = insert_first(head, ch, no);
	}*/

	head = insert_first(head, 'T', 1);
	head = insert_first(head, 'B', 2);
	head = insert_first(head, 'C', 3);
	head = insert_first(head, 'F', 4);
	head = insert_first(head, 'D', 5);
	head = insert_first(head, 'S', 6);

	print_list(head);

	searchednode = seq_search(head, 4);

	if (searchednode)
		printf("%d, %c", searchednode->key, searchednode->data);
	else
		printf("Not found");

	return 0;
}