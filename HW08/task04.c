#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], i_max1=0, i_max2=1;
	for (int i=0; i < SIZE_ARR; i++)
	{
		scanf("%d", &arr[i]);
		if (i)
		{
			if (arr[i_max1] < arr[i])
			{
				i_max2 = i_max1;
				i_max1 = i;
			}
			else if (arr[i_max2] < arr[i])
				i_max2 = i;
		}
	}
	printf("%d", arr[i_max1] + arr[i_max2]);
	return 0;
}
