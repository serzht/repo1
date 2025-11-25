#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], arr1[SIZE_ARR]={0}, count=0;
	for (int i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (int i=0; i < SIZE_ARR; i++)
		if ((arr[i]/10)%10 == 0)
		{
			arr1[count] = arr[i];
			count++;
		}
	for (int i=0; i < count; i++)
		printf("%d ", arr1[i]);
	return 0;
}
