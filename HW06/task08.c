#include <stdio.h>

char to_uppercase (char c);

int main(int argc, char **argv)
{
	char c;
	while ((c=getchar())!='.')
		putchar(to_uppercase(c));
	return 0;
}

char to_uppercase (char c)
{
	if (c > 0x60 && c < 0x7B)
		return c-0x20;
	return c;
}
