#include <stdio.h>

int main()
{
	printf("2016-11-26 이승욱\n");

	int a, b;
	char op;
	int result;

	while (1)
	{
		printf("수식을 입력하세요 (0 0 0 입력시 종료): ");
		result = scanf("%d %c %d", &a, &op, &b);
		if (result < 3)
		{
			printf("잘못 입력하셨습니다\n"
				"<정수> <연산자> <정수>의 순으로 입력하세요.\n");
			continue;
		}

		if (a == 0 && op == '0' && b == 0)
			break;

		switch (op)
		{
		case '+':
			printf("%d + %d = %d\n", a, b, a + b);
			break;
		case '-':
			printf("%d - %d = %d\n", a, b, a - b);
			break;
		case '*':
			printf("%d * %d = %d\n", a, b, a * b);
			break;
		case '/':
			printf("%d / %d = %d\n", a, b, a / b);
			break;
		default:
			printf("잘못된 연산자입니다.\n");
			continue;
		}
	}

	return 0;
}