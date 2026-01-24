#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	int N, a, num=0;
	scanf("%u", &N);
	for (int i=0; i < N; i++){
		scanf("%d", &a);
		if (num)
			num ^= a;
		else
			num = a;
	}
	printf("%d\n", num);
	return 0;
}
