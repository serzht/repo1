#include <stdio.h>

int sum_of_units (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf("%d", sum_of_units(n));
	return 0;
}

int sum_of_units (int n)
{
	if (n)
		return n%2 + sum_of_units (n/2);
	return 0;
}
