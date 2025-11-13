#include <stdio.h>
#include <inttypes.h>

uint64_t count_grains(uint8_t n);

int main(int argc, char **argv)
{
	uint8_t n;
	scanf("%" SCNu8, &n);
	printf("%" PRIu64, count_grains(n));
	return 0;
}

uint64_t count_grains(uint8_t n)
{
	uint64_t a=1;
	return a<<(n-1);
}
