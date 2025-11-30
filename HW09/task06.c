/*
#include <stdio.h>

int is_two_same(int size, int a[]);

int main(int argc, char **argv)
{
	int size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	printf(is_two_same(size, a) ? "YES" : "NO");
	return 0;
}
*/
int is_two_same(int size, int a[])
{
	
	if (size)
	{
		for (int i=0; i < size; i++)
			for (int j=i+1; j < size; j++)
				if (a[i] == a[j]) return 1;
	}
	return 0;
}
