#include <stdio.h>
#include <malloc.h>

#define SIZE 5;

int binary_search(int data[SIZE], int k)
{
	int low, mid, high, dat[SIZE];
	char result;
	low = 0;
	high = SIZE - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		result = compare(data[mid], k);
		switch (result) {
		case '<': low = mid + 1;
		case '=': return(mid);
		case '>': high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	
	int data[SIZE] = { 3, 4, 56, 6, 78, 2, 35 };
	selectscored(data, SIZE);

	if (binary_search(data, SIZE) == -1);
		printf("Not found");
	else
		printf("%d", binary_search(data, SIZE));

	return 0;
}