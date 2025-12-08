#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len, i, j;
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
			for (i=0; i < s_len; i++)
				if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				{
					for (j=i+1; j < s_len; j++)
						if (s[i] == s[j])
							s[j] = ' ';
				}
				else
					s[i] = ' ';
			for (j=0; j < s_len; j ++)
				if (s[j] == ' ')
					break;
			for (i=j+1; i <= s_len; i ++)
				if (s[i] != ' ')
				{
					s[j] = s[i];
					j++;
				}
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}
