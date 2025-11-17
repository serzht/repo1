#include <stdio.h>

void print_n (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_n (n);
	return 0;
}

void print_n (int n)
{
	if (n>1) print_n (n-1);
	printf("%d ", n);
}
