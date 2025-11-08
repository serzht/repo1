#include <stdio.h>

int main(int argc, char **argv)
{
	int i, a ,b, sum=0;
	scanf("%d%d", &a, &b);
	for(i=a; a<=b && i<=b; i++)
		sum+=i*i;
	printf("%d", sum);
	return 0;
}

