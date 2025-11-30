#include <stdio.h>

float average_of_main_diagonal (int m, int a[][m]);

int main(int argc, char **argv)
{
	int m = 5, count=0; 
	float average_diag;
	int a[m][m];
	for (int i=0; i < m; i++)
		for (int j=0; j < m; j++)
			scanf("%d", &a[i][j]);
	average_diag = average_of_main_diagonal (m, a);
	for (int i=0; i < m; i++)
		for (int j=0; j < m; j++)
			if (a[i][j] > 0 && a[i][j] > average_diag)
				count++;	
	printf("%d", count);
	return 0;
}

float average_of_main_diagonal (int m, int a[][m])
{
	int sum=0;
	for (int i=0; i < m; i++)
		sum += a[i][i];
	return (float)sum/m;
}
