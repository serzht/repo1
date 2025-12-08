#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len, counter=0, j;
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
			for (int i=0; i <= s_len; i++)
				if (s[i] == ' ' || s[i] == '\0')
				{
					if (counter)
					{
						for (j = i - counter; j < i; j++) 
							fprintf(f, "%c", s[j]);
						fprintf(f, "\n");
						counter = 0;
					}
				}
				else
				{
					counter++;
				}
			fclose(f);
		}
	}
	return 0;
}
