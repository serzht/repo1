#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], t, flag;
	for (int i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (int i=1; i < SIZE_ARR; i++)
	{
		flag = 1;
		for (int j=0; j < SIZE_ARR-i; j++)
		{
			if (arr[j]%10 > arr[j+1]%10)
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}
	for (int i=0; i < SIZE_ARR; i++)
		printf("%d ", arr[i]);
	return 0;
}

