#include <stdio.h>

int sum_digits(int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d", sum_digits(n));
	return 0;
}

int sum_digits(int n)
{
	return n ? n%10 + sum_digits(n/10) : n;
}
