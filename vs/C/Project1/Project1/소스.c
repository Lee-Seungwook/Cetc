#include <stdio.h>

int main()
{
	printf("2016-11-07 �̽¿�\n");

	int x[3] = { 1, 2, 3 };
	int y[3] = { 4, 5, 6 };
	int z[3] = { 7, 8, 9 };
	int* arr[3] = { x, y, z };
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}


	return 0;
}