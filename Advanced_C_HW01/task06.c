#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	uint32_t N;
	scanf("%u", &N);
	printf("%u\n", N^0xFF000000);
	return 0;
}
