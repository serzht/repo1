#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	uint32_t N, sum=0;
	scanf("%u", &N);
	for (int i=0; i < 32; i++)
		if ((N>>i) & 0x1)
			sum++;
	printf("%u\n", sum);
	return 0;
}
