#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	do
	{
		printf("%d", n%10);
		n/=10;
	}
	while (n);
	return 0;
}
