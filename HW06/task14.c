#include <stdio.h>

int even_sum (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(even_sum(n) ? "YES" : "NO");
	return 0;
}

int even_sum (int n)
{
	int sum=0;
	while (n)
	{
		sum += n%10;
		n /= 10;
	}
	return sum % 2 ? 0 : 1;
}
