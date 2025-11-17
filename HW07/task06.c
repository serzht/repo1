#include <stdio.h>

void reverse_string(void);

int main(int argc, char **argv)
{
	reverse_string();
	return 0;
}

void reverse_string(void)
{
	char c=getchar();
	if (c != '.')
		reverse_string();
	else
		return;
	putchar(c);
}
