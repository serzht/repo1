#include <stdio.h>

void reverse_print_n(int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	reverse_print_n(n);
	return 0;
}

void reverse_print_n(int n)
{
	printf("%d ", n);
	if (n > 1)
		reverse_print_n(n-1);
}
