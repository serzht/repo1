#include <stdio.h>
#include <string.h>

#define SIZE 10001

int main(int argc, char **argv)
{
	int s_len, num_stones=0, i, i_, j;
	char s[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\EOF]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s_len = strlen(s);
			for (i=0; i < s_len; i++)
				if (s[i] == '*') num_stones++;
			for (i=1, j=num_stones; j > 0;i++)
				j -= i;
			i_=i;
			if (j == 0 && num_stones)
				for (i=1; i < i_; i++)
				{
					for (j=1; j < i_- i; j++)
						fprintf(f, " ");
					for (j=1; j < i; j++)
						fprintf(f, "* ");
					fprintf(f, "*\n");
				}
			else
				fprintf(f, "NO");
			fclose(f);
		}
	}
	return 0;
}
