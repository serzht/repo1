#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_api.h"

int size_info=0;

int main(int argc, char **argv)
{
	sensor *info = NULL;
	int  number, c;
	uint8_t month=0, help=0, print_info=0;
	char *filename=NULL;
	opterr = 0;
	while ((c = getopt(argc, argv, "hf:m:p")) != -1)
		switch (c) {
			case 'h': help = 1; break;
			case 'm': if (atoi(optarg) > 0 && atoi(optarg) <13) month = atoi(optarg); break;
			case 'f': if (strlen(optarg) > 1) filename = optarg; break;
			case 'p': print_info = 1;
		}
	if (help)
		printf("Temperature statistic application. Please enter key:\n\n-h\t\tFor help.\
		\n-f file_name\tFor download temperature data.\n-m xx\t\tStatistic for xx month.\n-p\t\tPrint the data array.\n");
	else if (filename) {
		number = AddInfo(&info, filename);
		if (number) {
			//SortByDate(info, number, forward);
			//SortByDate(info, number, reverse);
			//number = DeleteRecord(info, &number, 2021, 7, 16, 1, 1);
			if (print_info) PrintInfo(info, number);
			if (month)
				PrintMonth(info, number, month);
			else
				PrintYear(info, number);
		}
	}
	else if (month || print_info)
		printf("No data file specified.\n");
	else
		printf("Temperature statistic application. For help type -h.\n");
	if (info) free(info);
	return 0;
}
