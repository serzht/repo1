#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], i_max, max, i_min, min;
	for (int i=0; i<SIZE_ARR; i++)
	{
		scanf("%d", &arr[i]);
		if (i)
		{
			if (max < arr[i]) {	max = arr[i], i_max = i; }
			if (min > arr[i]) {	min = arr[i], i_min = i; }
		}
		else
		{
			max = min = arr[i];
			i_max = i_min = i;
		}
	}
	printf("%d %d %d %d", i_max+1, max, i_min+1, min);
	return 0;
}
