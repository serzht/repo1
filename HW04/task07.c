#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, n, max;
	scanf("%3d", &n);
	c = n%10;
	b = (n/10)%10;
	a = (n/100)%10;
	max = a > b ? a : b;
	max = max > c ? max : c;
	printf("%d", max);
	return 0;
}

