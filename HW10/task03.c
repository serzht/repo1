#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len;
	char s[SIZE], c;
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s_len = strlen(s);
			if (s_len) c=s[s_len-1];
			for (int i=0; i < s_len-1; i++)
				if (s[i] == c)
					fprintf(f, "%d ", i);
			fclose(f);
		}
	}
	return 0;
}

