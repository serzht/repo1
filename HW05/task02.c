#include <stdio.h>

int main(int argc, char **argv)
{
	int i, a, b;
	scanf("%d%d", &a, &b);
	for(i=a; a<=b && i<=b; i++)
		printf("%d ", i*i);
	return 0;
}

