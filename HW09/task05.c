/*
#include <stdio.h>

int find_max_array(int size, int a[]);

int main(int argc, char **argv)
{
	int size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	printf("%d", find_max_array(size, a));
	return 0;
}
*/
int find_max_array(int size, int a[])
{
	int max=0;
	if (size)
	{
		max = a[0];
		for (int i=1; i < size; i++)
			if (max < a[i])
				max = a[i];
	}
	return max;
}
