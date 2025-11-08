#include <stdio.h>

int main(int argc, char **argv)
{
	
	int n, countNine = 0;
	scanf("%d", &n);
	while (n)
	{
		if (n%10 == 9) countNine++;
		n/=10;
	}
	printf(countNine == 1 ? "YES" : "NO");
	return 0;
}
