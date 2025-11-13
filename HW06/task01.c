#include <stdio.h>

int ABS(int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d", ABS(n));
	return 0;
}

int ABS(int n)
{
	return n < 0 ? -n : n;
}
