/*
#include <stdio.h>

int count_between(int from, int to, int size, int a[]);

int main(int argc, char **argv)
{
	int from, to, size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	printf("Start counting elements from: \n");
	scanf("%d", &from);
	printf("Continue counting to the element: \n");
	scanf("%d", &to);
	printf("%d", count_between (from, to, size, a));
	return 0;
}
*/
int count_between(int from, int to, int size, int a[])
{
	int count_elements=0;
	if (to < from)
		to = to ^ from, from = to ^ from, to = to ^ from;
	for (int i=0; i < size; i++)
		if (a[i] >= from && a[i] <= to)
			count_elements++;
	return count_elements;
}
