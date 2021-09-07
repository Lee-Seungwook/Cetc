#include <stdio.h>
#include <stdlib.h>


int main()
{
	int arr[10] = { 8, 1, 3, 4, 5, 7, 2, 6, 9 };
	int i = 0;
	int max = 0;
	int j = 0;
	int k = 0;
	int temp = 0;

	for (i = 0; i < 10; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}

	printf("max: %d \n", max);

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i, 10; i++)
		{
			if (arr[k] > arr[k+1])
			{
				temp = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = temp;
			}
		}
	}




	printf("오름차순 정리:\n");

	for (i = 0; i < 10; i++)
	{

		printf("arr[%d] = %d \n", i + 1, arr[i]);
	}


	return 0;
}




