#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], sum_p=0;
	for (int i=0; i<SIZE_ARR; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > 0) sum_p += arr[i];
	}
	printf("%d", sum_p);
	return 0;
}
