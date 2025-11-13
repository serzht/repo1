#include <stdio.h>

int digit_to_num (char c);
int is_digit (char c);

int main(int argc, char **argv)
{
	char c, count=0;
	while ((c=getchar())!='.')
		if (is_digit(c))
			count += digit_to_num(c);
	printf("%d", count);
	return 0;
}

int digit_to_num (char c)
{
	if (c > 0x2F && c < 0x3A)
		return c-0x30;
	return c;
}

int is_digit (char c)
{
	if (c > 0x2F && c < 0x3A)
		return 1;
	return 0;
}
