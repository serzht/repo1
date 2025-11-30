/*
#include <stdio.h>

void swap_negmax_last(int size, int a[]);

int main(int argc, char **argv)
{
	int size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	swap_negmax_last(size, a);
	for (int i=0; i < size; i++)
		printf("%d ", a[i]);
	return 0;
}
*/
void swap_negmax_last(int size, int a[])
{
	int negmax=0, i_negmax;
	for (int i=0; i < size; i++)
			if (a[i] < 0 && (negmax == 0 || negmax < a[i]))
			{
				negmax = a[i];
				i_negmax = i;
			}
	if (negmax)
	{
		a[i_negmax] = a[i_negmax]^a[size-1];
		a[size-1] = a[i_negmax]^a[size-1];
		a[i_negmax] = a[i_negmax]^a[size-1];
	}
}
