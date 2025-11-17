#include <stdio.h>

int is_prime(int n, int delitel);

int main(int argc, char **argv)
{
	int n, delitel=2;
	scanf("%d", &n);
	printf(is_prime(n, delitel) && n > 1 ? "YES" : "NO");
	return 0;
}

int is_prime(int n, int delitel)
{
	if (delitel*delitel <= n)
		return n % delitel ? is_prime(n, delitel+1) : 0;
	return 1;
}
