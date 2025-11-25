#include <stdio.h>

#define SIZE_ARR 5

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], min;
	for (int i=0; i<SIZE_ARR; i++)
	{
		scanf("%d", &arr[i]);
		if ((i && min > arr[i]) || !i)
			min = arr[i];
	}
	printf("%d", min);
	return 0;
}
