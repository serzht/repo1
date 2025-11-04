#include <stdio.h>

int main(int argc, char **argv)
{
	short month;
	scanf("%hd", &month);
	if (month == 12 || month == 1 || month == 2) printf("winter");
	if (month == 3 || month == 4 || month == 5) printf("spring");
	if (month == 6 || month == 7 || month == 8) printf("summer");
	if (month == 9 || month == 10 || month == 11) printf("autumn");
	return 0;
}

