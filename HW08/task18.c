#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	for (int i=2; i<10; i++)
		printf("%d %d\n", i, n/i);
	return 0;
}

