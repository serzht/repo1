#include <stdio.h>

void print_prime_factors (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_prime_factors(n);
	return 0;
}

void print_prime_factors (int n)
{
	static int factor=2;
	if (n>1)
	{
		if (n % factor)
		{
			factor++;
			print_prime_factors(n);
		}
		else
		{ 
			printf("%d ", factor);
			print_prime_factors(n/factor);
		}
	}
}
