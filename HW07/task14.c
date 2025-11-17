#include <stdio.h>

void odd_numbers (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	odd_numbers(n);
	return 0;
}

void odd_numbers (int n)
{
	if (n != 0)
	{
		if (n % 2)
			printf("%d ", n);
		scanf("%d", &n);
		odd_numbers(n);
	}
}
