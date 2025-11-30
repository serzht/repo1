/*
#include <stdio.h>

int count_bigger_abs(int n, int a[]);

int main(int argc, char **argv)
{
	int size;
	printf("Set the array size: ");
	scanf("%d", &size);
	int a[size];
	printf("Enter the array elements: \n");
	for (int i=0; i < size; i++)
		scanf("%d", &a[i]);
	printf("%d", count_bigger_abs (size, a));
	return 0;
}
*/
int count_bigger_abs(int n, int a[])
{
	int count_ba=0, max = a[0];
	for (int i=0; i < n; i++)
		if (max < a[i])
			max = a[i];
	for (int i=0; i < n; i++)
		if (a[i] < 0 && a[i]*(-1) > max)
			count_ba++;
	return count_ba;
}
