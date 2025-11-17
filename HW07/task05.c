#include <stdio.h>

void dec_to_bin (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	dec_to_bin(n);
	return 0;
}

void dec_to_bin (int n)
{
	if (n/2)
		dec_to_bin(n/2);
	printf("%d", n%2);
}
