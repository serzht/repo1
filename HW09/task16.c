#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	int a, b;
	while ((c = getchar()) != '\n')
	{
		if (c > 0x60 && c < 0x69) a = c - 0x60;
		if (c > 0x40 && c < 0x49) a = c - 0x40;
		if (c > 0x30 && c < 0x39) b = c - 0x30;
 	}
 	if ((a%2 && b%2) || (!(a%2) && !(b%2)))
		printf("BLACK");
	else
		printf("WHITE");
	return 0;
}

