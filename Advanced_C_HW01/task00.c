#include <stdio.h>

int main(int argc, char **argv)
{
	int a, max, N=0, num=0, i=0;
	do{
		scanf("%d", &a);
		if (i){
			if (num){
				if (max < a){
					max = a;
					num = 1;
				}
				else if (max == a)
					num++;
			}
			else{
				max = a;
				num = 1;
			}
		}
		else
			N = a;
		i++;
	}
	while(i <= N);
	printf("%d\n", num);
	return 0;
}

