#include <stdio.h>

void num_k_times (int n);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	num_k_times(n);
	return 0;
}

void num_k_times (int n)
{
	static int i;
	int j;
	i++;
	if(n)
	{
		for (j=0; j<i && n-j; j++)
			printf("%d ", i);
		num_k_times(n-j);
	}
}
