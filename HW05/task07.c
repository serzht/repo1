#include <stdio.h>

int main(int argc, char **argv)
{
	int n, n1;
	scanf("%d", &n);
	while (n)
	{
		n1 = n;
		while (n1)
		{
			n1/=10;
			if (n%10 == n1%10)
			{
				printf("YES");
				return 0;
			}
		}
		n/=10;
	}
	printf("NO");
	return 0;
}
