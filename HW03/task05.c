#include <stdio.h>

int main(int argc, char **argv)
{
	int a, sum;
	scanf("%3d", &a);
	sum = a%10;
	sum *= (a/10)%10;
	sum *= (a/100)%10;
	printf("%d", sum);
	return 0;
}

