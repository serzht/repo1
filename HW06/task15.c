#include <stdio.h>

int grow_up (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	printf(grow_up(n) ? "YES" : "NO");
	return 0;
}

int grow_up (int n)
{
	while (n)
	{
		if (n%10 <= (n/10)%10)
			return 0;
		n/=10;
	}
	return 1;
}
