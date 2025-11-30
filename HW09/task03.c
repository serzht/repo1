#include <stdio.h>
#include <string.h>

#define SIZE 1000

void print_nums (char arr[]);

int main(int argc, char **argv)
{
	char arr[SIZE];
	scanf("%[0-9]", arr);
	print_nums(arr);
	return 0;
}

void print_nums (char arr[])
{
	int len = strlen(arr), arr_sum[10]={0}, i, start;
	for (i=0; i < len; i++)
		if (arr[i] > 48) break;
	start = len > i ? i: 0;
	for (i=start; i < len; i++)
		arr_sum[arr[i]-48]++;
	for (i=0; i < 10; i++)
		if (arr_sum[i]) printf("%d %d\n", i, arr_sum[i]);
}
