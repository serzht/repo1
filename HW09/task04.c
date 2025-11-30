/*
#include <stdio.h>
#include <string.h>
#define SIZE 1000

void print_digit(char s[]);

int main(int argc, char **argv)
{
	char s[SIZE] = "Hello123 world77.";
	print_digit(s);
	return 0;
}
*/
void print_digit(char s[])
{
	int len = strlen(s), arr_sum[10]={0};
	for (int i=0; i < len; i++)
		if (s[i] > 47 && s[i] < 58)
			arr_sum[s[i]-48]++;
	for (int i=0; i < 10; i++)
		if (arr_sum[i]) printf("%d %d\n", i, arr_sum[i]);
}
