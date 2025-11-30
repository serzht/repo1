#include <stdio.h>

int trace_matrix (int m, int a[][m]);

int main(int argc, char **argv)
{
	int m = 5;
	int a[m][m];
	for (int i=0; i < m; i++)
		for (int j=0; j < m; j++)
			scanf("%d", &a[i][j]);
	printf("%d", trace_matrix (m, a));
	return 0;
}

int trace_matrix (int m, int a[][m])
{
	int trace=0;
	for (int i=0; i < m; i++)
		for (int j=0; j < m; j++)
			if (i == j)
				trace += a[i][j];
	return trace;
}
