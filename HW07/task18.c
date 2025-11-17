#include <stdio.h>

void print_digits (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_digits (n);
	return 0;
}

void print_digits (int n)
{
	if (n/10)
		print_digits (n/10);
	printf("%d ", n%10);
}
