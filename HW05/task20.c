#include <stdio.h>

int main(int argc, char **argv)
{
	int i, n;
	scanf("%d", &n);
	if (n > 1) 
		for (i=2; n%i; i++);
	printf(n > 1 && i == n ? "YES" : "NO");
	return 0;
}

