#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], t, shift=1, index;
	for (int i=0; i<SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (int i=0; i < shift; i++)
		for (int j=SIZE_ARR-1; j > 0; j--)
		{
			index = j+1 >= SIZE_ARR ? 0 : j+1;
			t = arr[j];
			arr[j] = arr[index];
			arr[index] = t;
		}
	for (int i=0; i<SIZE_ARR; i++)
		printf("%d ", arr[i]);
	return 0;
}
