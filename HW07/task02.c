#include <stdio.h>

int sum_n (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d", sum_n(n));
	return 0;
}

int sum_n (int n)
{
	if (n>1) n += sum_n(n-1);
	return n;
}
