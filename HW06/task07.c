#include <stdio.h>

 int convert (int n, int p);

int main(int argc, char **argv)
{
	int n, p;
	scanf("%d%d", &n, &p);
	printf("\n%d", convert (n, p));
	return 0;
}

int convert (int n, int p)
{ 
	int i, j, k, n1=0;
	for (i=1; n; i++)
	{
		n1 = n1*10 + n%p;
		n = n/p;
	}
	for (j=1; n1; j++)
	{
		n = n*10 + n1%10;
		n1/=10;
	}
	for (k=0; i-j-k; k++)
		n*=10;
	return n;
}
