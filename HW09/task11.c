#include <stdio.h>
#define SIZE 30

int main(int argc, char **argv)
{
	int a[SIZE], min1, min2, i_min1, i_min2;
	for (int i=0; i < SIZE; i++)
		scanf("%d", &a[i]);
	min1=a[0];
	i_min1 = 0;
	for (int i=0; i < SIZE; i++)
		if (min1 > a[i])
		{
			min1 = a[i];
			i_min1 = i;
		}
	i_min2 = (i_min1 + 1) < SIZE ? i_min1 + 1 : 0;
	min2 = a[i_min2];
	for (int i=0; i < SIZE; i++)
		if (i != i_min1 && min2 > a[i])
		{
			min2 = a[i];
			i_min2 = i;
		}
	if (i_min1 < i_min2)
		printf("%d %d", i_min1, i_min2);
	else
		printf("%d %d", i_min2, i_min1);
	return 0;
}

