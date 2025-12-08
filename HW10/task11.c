#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len, num_words=0;
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
					if (i && s[i-1] == 'a')
						num_words++;
			fprintf(f, "%d", num_words);
			fclose(f);
		}
	}
	return 0;
}
