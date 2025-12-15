#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"

uint32_t size=0;

int main(int argc, char **argv)
{
	sensor *info=NULL;
	uint8_t month=0, help=0, number;
	char *filename=NULL;
	for (int i=0; i < argc; i++)
		if (!strcmp(argv[i],"-h")) {
			help=1; break;
		}
		else if (!strcmp(argv[i],"-f") && argv[i+1] && strcmp(argv[i+1],"-m")) {
			filename = argv[i+1]; i++;
		} 
		else if (!strcmp(argv[i],"-m") && atoi(argv[i+1])) {
			month = (uint8_t)atoi(argv[i+1]); i++;
		}
	if (help || (!filename && !month))
		printf("Temperature statistic application. Please enter key:\n\n-h\t\tfor help.\n-f file_name\tfor load this file.\n-m xx\t\tstatistic for xx month.\n");
	else if (filename){
		number = AddInfo(info, filename);
		if (number){
			if (month)
				PrintMonth(info, number, month);
			else
				PrintYear(info, number);
		}
	}
	else if (month)
		printf("No data file specified.\n");
	return 0;
}
