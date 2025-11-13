#include <stdio.h>

int function (int x);

int main(int argc, char **argv)
{
	int i=0, x, max=0;
	do
	{
		scanf("%d", &x);
		max = (max < function(x) || i==0) && x!=0 ? function(x) : max;
		i++;
	}
	while (x);
	printf("%d", max);
	return 0;
}

int function (int x)
{
	if (x >=-2 && x < 2)
		return x*x;
	else if (x >= 2)
		return x*x + 4*x + 5;
	else
		return 4;
}
