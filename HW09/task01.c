/*
#include <stdio.h>
#define SIZE 20

void sort_array(int size, int a[]);

int main(int argc, char **argv)
{
	int arr[SIZE]={20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
	sort_array(SIZE, arr);
	for (int i=0; i < SIZE; i++)
		printf("%d ", arr[i]);
	return 0;
}
*/
void sort_array(int size, int a[])
{
	int t, flag;
	for (int i=1; i < size; i++)
	{
		flag = 1;
		for (int j=0; j < size-i; j++)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag=0;
			}
		}
		if (flag) break;
	}
}
