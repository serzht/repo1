#include <stdio.h>

void reverse_digits (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	reverse_digits(n);
	return 0;
}

void reverse_digits (int n)
{
	printf("%d ", n%10);
	if (n/10)
		reverse_digits(n/10);
}
