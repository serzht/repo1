#include <stdio.h>
#include <string.h>

#define SIZE 1001

void palindrome (char *s);

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
			palindrome(s);
			fprintf(f, "%s", s);
			fclose(f);
		}
	}
	return 0;
}

void palindrome (char *s)
{
	int arr[123]={0}, s_len = strlen(s), counter=0, i, j, odd_index=0;	//a - z: 97 - 122
	for (i=0; i < s_len; i++)
			arr[(int)s[i]]++;
	for (i=97; i < 123; i++)
	{
		if (arr[i]%2 && !odd_index)
			odd_index = i;
		for (j=0; j < arr[i]/2; j++)
			s[counter++] = i;
	}
	j = counter;
	if (odd_index)
		s[counter++] = odd_index;
	for (i=j-1; i >= 0; i--)
		s[counter++] = s[i];
	s[counter] = '\0';
}
