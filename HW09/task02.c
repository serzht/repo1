/*
#include <stdio.h>
#define SIZE 20

void sort_even_odd(int n, int a[]);

int main(int argc, char **argv)
{
	int arr[SIZE] = {11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
	sort_even_odd (SIZE, arr);
	for (int i=0; i < SIZE; i++)
		printf("%d ", arr[i]);
	return 0;
}
*/
void sort_even_odd(int n, int a[])
{
	int flag, t;
	for (int i=1; i < n; i++)
	{
		flag = 1;
		for (int j=0; j < n-i; j++)
		{
			if (a[j]%2 && a[j+1]%2==0)
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}
}
