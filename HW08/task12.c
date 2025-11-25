#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], t, flag=1;
	for (int i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	while (flag)
	{
		flag = 0;
		for (int i=0; i < SIZE_ARR-1; i++)
		{
			if ((i < 4 && arr[i] > arr[i+1]) || (i > 4 && arr[i] < arr[i+1]))
			{
				t = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = t;
				flag = 1;
			}
		}
	}
	for (int i=0; i < SIZE_ARR; i++)
		printf("%d ", arr[i]);
	return 0;
}
