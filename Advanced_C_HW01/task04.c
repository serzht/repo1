#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	uint32_t N, K, max=0;
	scanf("%u%u", &N, &K);
	for (int i=0; i <= (32-K); i++)
		if (max < (N<<i)>>(32-K))
			max = (N<<i)>>(32-K);
	printf("%u\n", max);
	return 0;
}
