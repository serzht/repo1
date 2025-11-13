#include <stdio.h>

void print_simple (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_simple(n);
	return 0;
}

void print_simple (int n)
{
	for (int i=2; n>1;)
	{
		if (n%i)
			i++;
		else
		{
			printf("%d ", i);
			n/=i;
		}
	}
}
