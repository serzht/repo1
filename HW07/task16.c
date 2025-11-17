#include <stdio.h>

int is2pow (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(is2pow (n) ? "YES" : "NO");
	return 0;
}

int is2pow (int n)
{
	if (n % 2)
		return n/2 == 0 ? 1 : 0;
	return is2pow (n/2);
}
