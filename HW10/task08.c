#include <stdio.h>
#include <string.h>

#define SIZE 1001

int main(int argc, char **argv)
{
	int a[SIZE]={0}, a_len=0, s_len, num_digits=0;
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
				if (s[i] >= '0' && s[i] <= '9')
				{
					a[a_len] = a[a_len]*10 + s[i] - 0x30;
					num_digits++;
				}
				else if(num_digits)
				{
					num_digits = 0;
					a_len++;
				}
			if (num_digits)
				a_len++;
			for (int i=1; i < a_len; i++)
				for (int j=0; j < a_len-i; j++)
					if (a[j] > a[j+1])
					{
						a[j] = a[j] ^ a[j+1];
						a[j+1] = a[j] ^ a[j+1];
						a[j] = a[j] ^ a[j+1];
					}
			for (int i=0; i < a_len; i++)
				fprintf(f, "%d ", a[i]);
			fclose(f);
		}
	}
	return 0;
}
