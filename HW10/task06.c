#include <stdio.h>
#include <string.h>

#define SIZE 1001

int is_palindrom(char *str);

int main(int argc, char **argv)
{
	char s[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%s", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			fprintf(f, is_palindrom(s) ? "YES" : "NO");
			fclose(f);
		}
	}
	return 0;
}

int is_palindrom(char *str)
{
	int s_len = strlen(str), i;
	for (i=0; i < s_len/2; i++)
		if (str[i] != str[s_len-1-i]) break;
	return i == s_len/2 ? 1 : 0;
}
