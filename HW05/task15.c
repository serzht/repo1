#include <stdio.h>

int main(int argc, char **argv)
{
	int even=0, n;
	do
	{
		scanf("%d", &n);
		if (!(n%2)) even++;
	} 
	while (n);
	printf("%d", even-1);
	return 0;
}

