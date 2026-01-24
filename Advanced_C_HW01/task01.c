#include <stdio.h>

int main(int argc, char **argv)
{
	int N, c, i=0;
	scanf("%d", &N);
	while ((c=getchar()) != '\n'){
		if (c > 0x40 && c < 0x5B)
			printf("%c", 0x41 + (c-0x41 + N)%26);
		else if (c > 0x60 && c < 0x7B)
			printf("%c", 0x61 + (c-0x61 + N)%26);
		else if (i)
			printf("%c", c);
		i++;
	}
	return 0;
}

