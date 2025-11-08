#include <stdio.h>

int main(int argc, char **argv)
{
	int n, sum=0;
	scanf("%d", &n);
	while (n)
	{
		sum += n%10;
		n = n/10;
	}
	printf("%d", sum);
	return 0;
}

