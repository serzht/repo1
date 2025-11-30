#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(int argc, char **argv)
{
	char c[SIZE];
	scanf("%[a-z]", c);
	int len_c = strlen(c), counter=0;
	for (int i=1, j=0; i <= len_c; i++)
	{
		counter++;
		if (i == len_c || c[i] != c[j])
		{
			printf("%c%d", c[j], counter);
			counter=0;
			j = i;
		}
	}
	return 0;
}

