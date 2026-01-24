#include <stdio.h>
#include <stdint.h>

struct pack_array{
	uint32_t array; //поле для хранения упакованного массива для 0 и 1
	uint32_t count0 : 8; //счетчик нулей в array
	uint32_t count1 : 8; //счетчик единиц в array
};

void array2struct(int [], struct pack_array *);

int main(int argc, char **argv)
{
	int arr[32];
	struct pack_array p = {0, 0, 0};
	for (int i=0; i < 32; i++)
		scanf("%d", &arr[i]);
	array2struct(arr, &p);
	return 0;
}

void array2struct(int arr[], struct pack_array *p)
{
	for (int i=0; i < 32; i++){
		arr[i] ? p->count1++ : p->count0++;
		p->array |= arr[i] << (31 - i);
	}
	printf("%u %u %u\n", p->array, p->count0, p->count1);
}
