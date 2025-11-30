#include <stdio.h>
#define SIZE 10

int main(int argc, char **argv)
{
	int a[SIZE], even=0, odd=0, product, d;
	for (int i=0; i < SIZE; i++)
	{
		scanf("%d", &a[i]);
		if (a[i]%2)
			odd++;
		else
			even++;
	}
	if (even > odd)
	{
		for (int i=0; i < SIZE; i++)
			if (a[i]%2)
			{
				d = a[i];
				product = 1;
				for (int j=0; d; j++)
				{
					if ((d%10)%2)
						product *= d%10;
					d/=10;
				}
				a[i] = product;
			}
	}
	else
	{
		for (int i=0; i < SIZE; i++)
			if (a[i]%2 == 0)
			{
				d = a[i];
				product = 1;
				for (int j=0; d; j++)
				{
					if ((d%10)%2 == 0)
						product *= d%10;
					d/=10;
				}
				a[i] = product;
			}
	}
	for (int i=0; i < SIZE; i++)
		 printf("%d ", a[i]);
	return 0;
}
