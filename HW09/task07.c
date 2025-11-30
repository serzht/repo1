/*
#include <stdio.h>

int compression(int a[], int b[], int N);

int main(int argc, char **argv)
{
	int size_a, size_b;
	printf("Set the array size: ");
	scanf("%d", &size_a);
	int a[size_a], b[size_a];
	printf("Enter the elements of array a[%d]: \n", size_a);
	for (int i=0; i < size_a; i++)
		scanf("%d", &a[i]);
	size_b = compression(a, b, size_a);
	for (int i=0; i < size_b; i++)
	{
		if (i) printf(",");
		printf("%d", b[i]);
	}
	return 0;
}
*/
int compression(int a[], int b[], int N)
{
	int len_b=0, counter=0;
	if (a[0])
	{
		b[0] = 0;
		len_b++;
	}
	for (int i=1; i <= N; i++)
	{
		counter++;
		if (i == N || a[i] != a[i-1])	//При i = N  a[i] находится за рамками массива,
		{								//но условие a[i] != a[i-1] не проверяется, т.к. i == N - истина
			b[len_b] = counter;
			counter=0;
			len_b++;
		}
	}
	return len_b;
}
