#include <stdio.h>

int main(int argc, char **argv)
{
	int n, even=0, odd=0;
	scanf("%d", &n);
	while (n)
	{
		if ((n%10)%2)
			odd++;
		else
			even++;
		n/=10;
	}
	printf("%d %d", even, odd);
	return 0;
}

