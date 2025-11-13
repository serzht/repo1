#include <stdio.h>

int gcd (int a, int b);

int main(int argc, char **argv)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd (a, b));
	return 0;
}

int gcd (int a, int b)	//Greatest Common Divisor
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
