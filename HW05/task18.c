#include <stdio.h>

int main(int argc, char **argv)
{
	int n, sum, num1=1, num2=1;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		printf("%d ", num1);
		sum = num1 + num2;
		num1 = num2;
		num2 = sum;
	}
	return 0;
}

