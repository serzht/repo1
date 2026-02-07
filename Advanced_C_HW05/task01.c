#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char str1[10000], str2[10000];
	int i, j, str1_len, str2_len, max_prefix=0, max_suffix=0;
	scanf("%s%s", str1, str2);
	str1_len = strlen(str1);
	str2_len = strlen(str2);
	for (i = str1_len >= str2_len ? str2_len : str1_len; i > 0; i--){
		for (j=0; j < i; j++)
			if (str1[j] != str2[str2_len - i + j]) break;
		if (i == j) break;
	}
	max_prefix = i;
	for (i = str1_len >= str2_len ? str2_len : str1_len; i > 0; i--){
		for (j=0; j < i; j++)
			if (str2[j] != str1[str1_len - i + j]) break;
		if (i == j) break;
	}
	max_suffix = i;
	printf("%d %d\n", max_prefix, max_suffix);
	return 0;
}

