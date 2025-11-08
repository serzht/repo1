#include <stdio.h>

int main(int argc, char **argv)
{
	char c;
	while ((c=getchar())!='.')
		if (c > 0x40 && c < 0x5B)
			putchar(c+0x20);
		else
			putchar(c);
	return 0;
}

