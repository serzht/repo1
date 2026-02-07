#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char c, arr1[10][10][10]={{{0}}};
	int counter=0, n=0, max_size=10, *arr = malloc(max_size*sizeof(int));
	while ((c=getchar()) != '\n'){
		if (c >= '0' && c <= '9'){
			if (n == max_size){
				max_size *= 2;
				arr = realloc(arr, max_size*sizeof(int));
			}
			arr[n] = c-'0';
			n++;
		}
	}
	for (int i=0; i < n-2; i++){
		for (int j=i+1; j < n-1; j++){
			for (int k=j+1; k < n; k++){
				if (arr1[arr[i]][arr[j]][arr[k]] != 1 && arr[i]){
					arr1[arr[i]][arr[j]][arr[k]] = 1;
					counter++;
				}
			}
		}
	}
	printf("%d\n", counter);
	return 0;
}

