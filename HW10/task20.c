#include <stdio.h>
#include <string.h>

#define SIZE 1001

int is_palindrom (char *s);

int main(int argc, char **argv)
{
	char s[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%[^\n]", s);
		fclose(f);
		printf(is_palindrom(s) ? "YES" : "NO");
	}
	return 0;
}

int is_palindrom (char *s)
{
	int arr[123]={0}, s_len = strlen(s), counter=0;
	for (int i=0; i < s_len; i++)
			arr[(int)s[i]]++;
	for (int i=97; i < 123; i++)
		if (arr[i]%2) counter++;
	return counter < 2 ? 1 : 0;
}
