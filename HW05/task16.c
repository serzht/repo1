#include <stdio.h>

int main(int argc, char **argv)
{
	int num, num1, num2;
	scanf("%d%d", &num1, &num2);
	while (num2)
	{
		num = num1 % num2;
		num1 = num2;
		num2 = num;
	}
	printf("%d", num1);
	return 0;
}

