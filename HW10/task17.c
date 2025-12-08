#include <stdio.h>
#include <string.h>

#define SIZE 1001

void swap_pairs_char (char *s);

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
			swap_pairs_char (s);
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}

void swap_pairs_char (char *s)
{
	int s_len = strlen(s), counter=0, index1, index2;
	for (int i=0; i < s_len; i++)
	{
		if (s[i] != ' ')
		{
			counter++;
			if (counter == 1)
				index1 = i;
			else
				index2 = i;
		}
		if (counter == 2)
		{
			s[index1] = s[index1] ^ s[index2];
			s[index2] = s[index1] ^ s[index2];
			s[index1] = s[index1] ^ s[index2];
			counter = 0;
		}
	}
}
