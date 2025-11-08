#include <stdio.h>

int main(int argc, char **argv)
{
	int n, sum, product;
	scanf("%d", &n);
	for (int i=10; i <= n; i++)
	{
		sum = 0;
		product = 1;
		for (int j=i; j;)
		{
			sum += j%10;
			product *= j%10;
			j/=10;
		}
		if (sum == product) printf("%d ", i);
	}
	return 0;
}

