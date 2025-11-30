#include <stdio.h>

int find_max_in_string (int m, int a[]);

int main(int argc, char **argv)
{
	int m = 10, sum = 0;
	int a[m][m];
	for (int i=0; i < m; i++)
		for (int j=0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i=0; i < m; i++)
		sum += find_max_in_string (m, a[i]);
	printf("%d", sum);
	return 0;
}

int find_max_in_string (int m, int a[])
{
	int max=a[0];
	for (int i=0; i < m; i++)
		if (max < a[i])
			max = a[i];
	return max;
}
