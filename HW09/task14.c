/*
#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[]);

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
	printf("%d", sum_between_ab (from, to, size, a));
	return 0;
}
*/
int sum_between_ab(int from, int to, int size, int a[])
{
	int sum_elements=0;
	if (to < from)
		to = to ^ from, from = to ^ from, to = to ^ from;
	for (int i=0; i < size; i++)
		if (a[i] >= from && a[i] <= to)
			sum_elements += a[i];
	return sum_elements;
}
