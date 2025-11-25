#include <stdio.h>

#define SIZE_ARR 20

int main(int argc, char **argv)
{
	unsigned long long int n;
	int arr[SIZE_ARR], i;
	scanf("%llu", &n);
	for (i=0; n; i++)
	{
		arr[i] = n%10;
		n/=10;
	}
	for (int j=i-1; j>=0; j--)
		printf("%d ", arr[j]);
	return 0;
}

