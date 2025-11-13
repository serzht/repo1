#include <stdio.h>

int is_prime (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(is_prime(n) ? "YES" : "NO");
	return 0;
}

int is_prime (int n)
{
	for (int i=2; n>=i*i; i++)
		if (!(n%i))
			return 0;
	return n>1 ? 1 : 0;
}
