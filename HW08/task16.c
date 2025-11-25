#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], count, num, max_count=0, i;
	for (i=0; i < SIZE_ARR; i++)
		scanf("%d", &arr[i]);
	for (i=0; i < SIZE_ARR; i++)
	{
		count=0;
		for (int j=i+1; j < SIZE_ARR; j++)
			if (arr[i] == arr[j])
				count++;
		if (count > max_count)
		{
			num = arr[i];
			max_count = count;
		}
	}
	printf("%d", num);
	return 0;
}

