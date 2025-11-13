#include <stdio.h>

int sum_numbers(int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d", sum_numbers(n));
	return 0;
}

int sum_numbers(int n)
{
	return n*(1+n)/2;
}
