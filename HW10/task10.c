#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len, index, word=0, index_max, word_max=0;
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
				if (s[i] != ' ' && s[i] != '\0')
				{
					if (word == 0)
						index = i;
					word++;
				}
				else
				{
					if (word > word_max)
					{
						index_max = index;
						word_max = word;
					}
					word = 0;
				}
			for (int i=index_max; i < index_max + word_max; i++)
				fprintf(f, "%c", s[i]);
			fclose(f);
		}
	}
	return 0;
}
