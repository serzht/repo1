#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	uint32_t N, K;
	scanf("%u%u", &N, &K);
	printf("%u\n", (N<<(32-K))>>(32-K));
	return 0;
}
