#include <stdio.h>

int main(int argc, char **argv)
{
	int arr[13]={1}, i, j, k, sum1, sum2, count=0, n;
	scanf("%d", &n);
	for (int i=1; i < 13; i++)
		arr[i] = arr[i-1]*3;
	for (i=1; i < 1594323; i++){
		k=i, sum1 = n, sum2=0, count=0;
		for (j=0; j < 13; j++){
			if (k){
				if (k%3 == 1) {
					sum1 += arr[j];
					count++;
				}
				else if (k%3 == 2){
					sum2 += arr[j];
					count++;
				}
				if (sum1 == sum2){
					if (sum1 > 1000000 || sum2 > 1000000)
						printf("-1\n");
					else
						printf("%d\n", count);
					return 0;
				}
			}
			else
				break;
			k/=3;
		}
	}
	printf("-1\n");
	return 0;
}

