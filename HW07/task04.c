#include <stdio.h>

void print_num (int num);

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	print_num(n);
	return 0;
}

void print_num (int num)
{
	if (num/10) print_num (num/10);
	printf("%d ", num%10);
}
