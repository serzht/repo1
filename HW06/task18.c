#include <stdio.h>

int is_digit (char c);

int main(int argc, char **argv)
{
	char c, count=0;
	while ((c=getchar())!='.')
		if (is_digit(c))
			count++;
	printf("%d", count);
	return 0;
}

int is_digit (char c)
{
	if (c > 0x2F && c < 0x3A)
		return 1;
	return 0;
}
