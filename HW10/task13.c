#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len;
	char s[SIZE], str[]={".html"};
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s_len = strlen(s);
			for (int i=s_len-1; i >= 0; i--)
				if (s[i] == '/')
				{
					for (int j=s_len; j < s_len + 6; j++)
						s[j] = str[j-s_len];
					break;
				}
				else if (s[i] == '.')
				{
					for (int j=i; j < i + 6; j++)
						s[j] = str[j-i];
					break;
				}
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}
