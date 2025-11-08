
#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	while (n)
	{
		if (n%10 <= (n/10)%10)
		{
			printf("NO");
			return 0;
		}
		n/=10;
	}
	printf("YES");
	return 0;
}

