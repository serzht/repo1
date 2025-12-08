#include <stdio.h>
#include <string.h>

#define SIZE 10001

int main(int argc, char **argv)
{
	int s_len, upper=0, lower=0;
	char s[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s_len = strlen(s);
			for (int i=0; i < s_len; i++)
				if (s[i] > 0x60 && s[i] < 0x7B)
					lower++;
				else if (s[i] > 0x40 && s[i] < 0x5B)
					upper++;
			fprintf(f, "%d %d", lower, upper);
			fclose(f);
		}
	}
	return 0;
}
