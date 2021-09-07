#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return s->top == -1;
}

int is_full(StackType *s) {
	return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType *s, int item) {
	if (is_full(s))
		exit(1);
	s->stack[++(s->top)] = item;
}

int pop(StackType *s) {
	if (is_empty(s))
		exit(1);
	return s->stack[(s->top)--];
}

int peek(StackType *s) {
	if (is_empty(s))
		exit(1);
	return s->stack[s->top];
}

//===== ���� �ڵ��� �� =====

//�������� �켱������ ��ȯ�Ѵ�.
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[]) {
	int i;
	char ch, top_op;
	int len = (int)strlen(exp);

	StackType s;
	init(&s);

	for (i = 0; i < len; i++) {
		ch = (int)exp[i];

		switch (ch) {
		case '+': case '-': case '*': case '/': //������
		   // ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s))) {
				printf("%c ", pop(&s));
			}
			push(&s, ch);
			break;
		case '(': //���� ��ȣ
			push(&s, ch);
			break;
		case ')': //������ ��ȣ
			top_op = pop(&s);
			//���� ��ȣ�� ���� ������ ���
			while (top_op != '(') {
				printf("%c ", top_op);
				top_op = pop(&s);
			}
			break;

		default: //�ǿ�����
			printf("%c ", ch);
			break;
		}
	}

	while (!is_empty(&s)) //���ÿ� ����� �����ڵ� ���
		printf("%c ", pop(&s));
}

int main() {
	char *s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s \n", s);
	printf("����ǥ�ü��� ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}