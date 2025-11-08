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
	printf(sum == 10 ? "YES" : "NO");
	return 0;
}

