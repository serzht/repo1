#include <stdio.h>

int main(int argc, char **argv)
{
	int i=0, n;
	scanf("%d", &n);
	do
	{
		n = n/10;
		i++;
	}
	while (n);
	if (i == 3) printf("YES"); else printf("NO");
	return 0;
}

