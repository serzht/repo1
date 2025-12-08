#include <stdio.h>

#define SIZE 101

int main(int argc, char **argv)
{
	char surname[SIZE], first_name[SIZE], patronymic[SIZE];
	FILE *f = fopen("input.txt", "r");
	if (f)
	{
		fscanf(f, "%s%s%s", surname, first_name, patronymic);
		fclose(f);
		f = fopen("output.txt", "w");
		if (f)
		{
			fprintf(f, "Hello, %s %s!", first_name, surname);
			fclose(f);
		}
	}
	return 0;
}
