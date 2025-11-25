#include <stdio.h>

#define SIZE_ARR 5

int main(int argc, char **argv)
{
	int arr[SIZE_ARR], sum=0;
	for (int i=0; i<SIZE_ARR; i++)
	{
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	printf("%.3f", (float)sum/SIZE_ARR);
	return 0;
}
