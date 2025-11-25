#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], arr1[SIZE_ARR]={0}, count=0, k;
	for (int i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (int i=0; i < SIZE_ARR; i++)
		for (int j=i+1; j < SIZE_ARR; j++)
			if (arr[i] == arr[j])
			{
				for (k=0; k < count; k++)
					if (arr1[k] == arr[i]) break;
				if (k == count)
				{
					arr1[count] = arr[i];
					count++;
				}
			}
	for (int i=0; i < count; i++)
		printf("%d ", arr1[i]);
	return 0;
}
