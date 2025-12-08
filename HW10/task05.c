#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len;
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
				switch (s[i])
				{
					case 'a':
						fprintf(f, "b"); break;
					case 'b':
						fprintf(f, "a"); break;
					case 'A':
						fprintf(f, "B"); break;
					case 'B':
						fprintf(f, "A"); break;
					default:
						fprintf(f, "%c", s[i]); break;
				}
			fclose(f);
		}
	}
	return 0;
}
