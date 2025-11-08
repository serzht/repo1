#include <stdio.h>

int main(int argc, char **argv)
{
	int countN=0, n;
	do
	{
		scanf("%d", &n);
		countN++;
	} 
	while (n);
	printf("%d", countN-1);
	return 0;
}

