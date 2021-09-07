#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct stacknode {
	int data;
	struct stacknode *link;
}stacknode;

typedef struct {
	stacknode *top;
}linkedstacktype;

void init(linkedstacktype *s)
{
	s->top = NULL;
}

int is_empty(linkedstacktype *s)
{
	return(s->top == NULL);
}

int is_full(linkedstacktype *s)
{
	return 0;
}

void push(linkedstacktype *s, element item)
{
	stacknode *temp = (stacknode *)malloc(sizeof(stacknode));
	temp -> data = item;
	temp -> link = s -> top;
	s -> top = temp;
}

void print_strack(linkedstacktype *s)
{
	for (stacknode *p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

element peek(linkedstacktype *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

element pop(linkedstacktype *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		stacknode *temp;
		temp = s->top;
		int data = temp->data;
		s->top = temp->link;
		
		free(temp);

		return data;
	}
}

int main(void)
{
	linkedstacktype s;
	init(&s);
	push(&s, 1); printf_stack(&s);
	push(&s, 2); printf_stack(&s);
	push(&s, 3); printf_stack(&s);
	pop(&s); printf_stack(&s);
	pop(&s); printf_stack(&s);
	pop(&s); printf_stack(&s);
	return 0;
}