#include <stdio.h>

int max_find (int max);

int main(int argc, char **argv)
{
	int max;
	scanf("%d", &max);
	printf("%d", max_find (max));
	return 0;
}

int max_find (int max)
{
	int n;
	scanf("%d", &n);
	if (n)
	{
		if (n > max)
			max = n;
		max = max_find (max);
	}
	return max;
}
