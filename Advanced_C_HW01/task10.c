#include <stdio.h>
#include <stdint.h>

int extractExp(float);

int main(int argc, char **argv)
{
	float a;
	scanf("%f", &a);
	printf("%d\n", extractExp(a));
	return 0;
}

int extractExp(float a)
{
	union float_bits{
		float value;
		uint32_t bits;
	} f;
	f.value = a;
	return (f.bits << 1) >> 24;
}
