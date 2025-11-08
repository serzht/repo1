#include <stdio.h>

int main(int argc, char **argv)
{
	int n, max=0, min=10;
	scanf("%d", &n);
	do
	{
		max = n%10 > max ? n%10 : max;
		min = n%10 < min ? n%10 : min;
		n/=10;
	}
	while (n);
	printf("%d %d", min, max);
	return 0;
}

