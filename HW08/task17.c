#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[2][SIZE_ARR]={0};
	for (int i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[1][i]);
	for (int i=0; i < SIZE_ARR; i++)
	{
		for (int j=i+1; j < SIZE_ARR; j++)
			if (arr[1][i] == arr[1][j])
			{
				arr[0][i] = 1;
				arr[0][j] = 1;
			}
	}
	for (int i=0; i < SIZE_ARR; i++)
		if (arr[0][i] == 0)
			printf("%d ", arr[1][i]);
	return 0;
}
