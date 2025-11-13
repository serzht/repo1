#include <stdio.h>

int is_happy_number (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(is_happy_number(n) ? "YES" : "NO");
	return 0;
}

int is_happy_number (int n)
{
	int sum=0, product=1;
	while (n)
	{
		sum += n%10;
		product *= n%10;
		n /= 10;
	}
	return sum == product ? 1 : 0;
}
