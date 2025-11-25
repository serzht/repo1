#include <stdio.h>

#define SIZE_ARR 10

int main(int argc, char **argv)
{
	int a, arr1[SIZE_ARR]={0}, arr2[SIZE_ARR]={0}, count_arr1=0, count_arr2=0;
	for (int i=0; i < SIZE_ARR; i++)
	{
		scanf("%d", &a);
		if (a > 0)
		{
			arr1[count_arr1] = a;
			count_arr1++;
		}
		else if (a < 0)
		{
			arr2[count_arr2] = a;
			count_arr2++;
		}
	}
	for (int i=0; i < count_arr1; i++)
		printf("%d ", arr1[i]);
	for (int i=0; i < count_arr2; i++)
		printf("%d ", arr2[i]);
	return 0;
}
