#include <stdio.h>
#include <string.h>

#define SIZE 1001

void trim (char *s);

int main(int argc, char **argv)
{
	char s[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			trim(s);
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}

void trim (char *s)
{
	int s_len = strlen(s), flag=1;
	for (int i=0; i < s_len; i++)
	{
		if (flag)
			if (s[i] == ' ')
			{
				for (int j=i; j < s_len; j++)
					s[j] = s[j+1];
				s_len--;
				i--;
			}
			else
				flag = 0;
		else
			if (s[i] == ' ' && s[i+1] == ' ')
			{
				for (int j=i; j < s_len; j++)
					s[j] = s[j+1];
				s_len--;
				i--;
			}
	}
}
