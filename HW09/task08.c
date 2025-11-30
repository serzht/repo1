#include <stdio.h>
#define SIZE 1000

int main(int argc, char **argv)
{
	int arr[SIZE] = {0}, i, size_arr, flag=1, t;
	for (i=0; i < SIZE; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == 0) break;
	}
	size_arr = i;
	for (i=1; flag && i < size_arr; i++)
	{
		flag = 0;
		for (int j=0; j < size_arr-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				flag = 1;
			}
		}
	}
	for (i=1; i < size_arr; i++)
		if (arr[i]-arr[i-1] > 1)
		{
			printf("%d ", arr[i]-1);
			break;
		}
	return 0;
}

