#include <stdio.h>
#include <string.h>

#define SIZE 101

int main(int argc, char **argv)
{
	int s1_len, s2_len, s3_len=0, count, i, j, k;
	char s1[SIZE], s2[SIZE], s3[SIZE]={0};
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%s%s", s1, s2);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			s1_len = strlen(s1);
			s2_len = strlen(s2);
			if (s1_len && s2_len)
			{
				for (i=0; i < s1_len; i++)
					if (s1[i])
					{
						count=0;
						for (j=i+1; j < s1_len; j++)
							if (s1[i] == s1[j])
							{
								s1[j] = 0;
								count++;
							}
						if (count == 0)
						{
							for (k=0; k < s2_len; k++)
								if (s1[i] == s2[k])
									if (++count > 1) break;
							if (count == 1)
								s3[s3_len++] = s1[i];
						}
					}
				count = 0;
				for (i=1; i < s3_len; i++)
				{
					for (j=0; j < s3_len-i; j++)
						if (s3[j] > s3[j+1])
						{
							s3[j] = s3[j] ^ s3[j+1];
							s3[j+1] = s3[j] ^ s3[j+1];
							s3[j] = s3[j] ^ s3[j+1];
							count++;
						}
					if (!count) break;
				}
				for (i=0; i < s3_len; i++)
					fprintf(f, "%c ", s3[i]);
			}
			fclose(f);
		}
	}
	return 0;
}
