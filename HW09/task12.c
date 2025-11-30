/*
#include <stdio.h>

void change_max_min(int size, int a[]);

int main(int argc, char **argv)
{
	int size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	change_max_min (size, a);
		
	for (int i=0; i < size; i++)
		printf("%d ", a[i]);
	return 0;
}
*/
void change_max_min(int size, int a[])
{
	int max, i_max, min, i_min;
	if (size)
	{
		max = a[0];
		min = a[0];
		i_max = i_min = 0;
		for (int i=1; i < size; i++)
		{
			if (max < a[i]) { max = a[i], i_max = i; } 
			if (min > a[i])	{ min = a[i], i_min = i; }
		}
		a[i_max] = a[i_max]^a[i_min];
		a[i_min] = a[i_max]^a[i_min];
		a[i_max] = a[i_max]^a[i_min];
	}
}
