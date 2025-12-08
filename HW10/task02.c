#include <stdio.h>

#define SIZE 27

int main(int argc, char **argv)
{
	int n;
	char s[SIZE]={0};
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%d", &n);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			for (int i=0; i < n/2; i++)
			{
				s[i*2] = 'A' + i;
				s[i*2+1] = 	i==0 || (s[i*2-1] + 2 > '8') ? '2' : s[i*2-1] + 2;
			}
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}

