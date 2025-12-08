#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int s_len, a_len, b_len, s1_len=0, i, j, k;
	char s[SIZE], s1[SIZE]={0}, a[]={"Ling"}, b[]={"Cao"};
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s_len = strlen(s);
			a_len = strlen(a);
			b_len = strlen(b);
			for (i=0; i <= s_len; i++)
			{
				for (j=i, k=0; j < i + a_len; j++, k++)
					if (s[j] != a[k]) break;
				if (j == i + a_len)
				{
					for (k=0; k < b_len; k++)
						s1[s1_len++] = b[k];
					i = i + a_len - 1;
				}
				else
					s1[s1_len++] = s[i];
			}
			fprintf(f, "%s", s1);
			fclose(f);
		}
	}
	return 0;
}
