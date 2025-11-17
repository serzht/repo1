#include <stdio.h>

int recurs_power (int n, int p);

int main(int argc, char **argv)
{
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d", recurs_power(n, p));
	return 0;
}

int recurs_power (int n, int p)
{
	if (p > 0)
		return n*recurs_power (n, p-1);
	return 1;
}
