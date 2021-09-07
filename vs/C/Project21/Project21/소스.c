#include<stdio.h>

void Bubble_Sort(int list[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - j - 1; i++) {
			if (list[i] > list[i + 1]) {
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
		}

}

void Selection_Sort(int list[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (list[i] > list[j]) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

void Insertion_Sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		j = i - 1;
		key = list[i];
		while (key < list[j] && j >= 0) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

void Shell_Sort(int list[], int n)
{
	int d = 0, i, j;
	int temp;

	d = n / 2;
	while (d > 0) {
		for (i = d; i < n; i++) {
			temp = list[i];
			for (j = i - d; j >= 0; j = j - d)
			{
				if (temp < list[j]) list[j + d] = list[j];
				else
					break;
			}
			list[j + d] = temp;
		}
		d = d / 2;
	}
}

int main()
{
	int list[5] = { 34, 38, 67, 46, 30 };

	printf("버블 정렬 결과를 출력\n");
	Bubble_Sort(list, 5);
	for (int i = 0; i < 5; i++)
		printf("%3d", list[i]);
	printf("\n");

	printf("선택 정렬 결과를 출력\n");
	Selection_Sort(list, 5);
	for (int i = 0; i < 5; i++)
	   printf("%3d", list[i]);
	printf("\n");

	printf("삽입 결과를 출력\n");
	Insertion_Sort(list, 5);
	for (int i = 0; i < 5; i++)
	   printf("%3d", list[i]);
	printf("\n");

	printf("쉘 정렬 결과를 출력\n");
	Shell_Sort(list, 5);
	for (int i = 0; i < 5; i++)
	   printf("%3d", list[i]);
	printf("\n"); 

	return 0;
}
