#include <stdio.h>

#define SIZE_ARR 20

int main(int argc, char **argv)
{
	unsigned long long int n;
	int arr[SIZE_ARR], count=0, flag, t;
	scanf("%llu", &n);
	for (int i=0; n; i++)
	{
		arr[i] = n%10;
		n/=10;
		count++;
	}
	for (int i=0; i < count-1; i++)
	{
		flag = 1;
		for (int j=0; j < count-1-i; j++)
		{
			if (arr[j] < arr[j+1])
			{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
				flag = 0;
			}
		}
		if (flag) break;
	}
	for (int i=0; i < count; i++)
		printf("%d", arr[i]);
	return 0;
}

