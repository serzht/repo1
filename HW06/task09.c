#include <stdio.h>

unsigned long long factorial (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%llu", factorial(n));
	return 0;
}

unsigned long long factorial (int n)
{
	unsigned long long result=1;
	for (int i=1; i<=n; i++)
		result *= i;
	return result;
}
