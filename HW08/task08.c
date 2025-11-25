#include <stdio.h>

#define SIZE_ARR 12

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], t;
	for (int i=0; i<SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (int i=0; i<SIZE_ARR/6; i++)
	{
		t = arr[i];
		arr[i] = arr[SIZE_ARR/3-1-i];
		arr[SIZE_ARR/3-1-i] = t;
		
		t = arr[i+SIZE_ARR/3];
		arr[i+SIZE_ARR/3] = arr[SIZE_ARR*2/3-1-i];
		arr[SIZE_ARR*2/3-1-i] = t;
		
		t = arr[i+SIZE_ARR*2/3];
		arr[i+SIZE_ARR*2/3] = arr[SIZE_ARR-1-i];
		arr[SIZE_ARR-1-i] = t;
	}
	for (int i=0; i<SIZE_ARR; i++)
		printf("%d ", arr[i]);
	return 0;
}
