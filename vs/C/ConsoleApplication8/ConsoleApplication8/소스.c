#include <stdio.h>

int main()
{
	printf("2016-11-26 �̽¿�\n");

	int a, b;
	char op;
	int result;

	while (1)
	{
		printf("������ �Է��ϼ��� (0 0 0 �Է½� ����): ");
		result = scanf("%d %c %d", &a, &op, &b);
		if (result < 3)
		{
			printf("�߸� �Է��ϼ̽��ϴ�\n"
				"<����> <������> <����>�� ������ �Է��ϼ���.\n");
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
			printf("�߸��� �������Դϴ�.\n");
			continue;
		}
	}

	return 0;
}