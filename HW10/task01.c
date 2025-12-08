#include <stdio.h>
#include <string.h>

#define SIZE 101

int main(int argc, char **argv)
{
	char arr[SIZE]={0};
	FILE *fp = fopen("input.txt", "r");
	if (fp)
	{
		fscanf(fp, "%[^\n]", arr);
		fclose(fp);
		fp = fopen("output.txt", "w");
		if (fp)
		{
			fprintf(fp, "%s, %s, %s %lld", arr, arr, arr, strlen(arr));
			fclose(fp);
		}
	}
	return 0;
}

