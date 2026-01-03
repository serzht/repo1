#include "temp_functions.h"

int main(int argc, char **argv)
{
	info_node *info = NULL;
	int month=0, help=0, print_info=0, sort=0;
	char *f_input=NULL, *f_output=NULL, *t_string=NULL;
	for (int i=1; i < argc; i++){
		if (argv[i][0] == '-'){
			switch (argv[i][1]){
				case 'h':
					help = 1; break;
				case 'f':
					if (argv[i][2] != '\0')
						f_input = &argv[i][2];
					else if (i+1 < argc && argv[i+1][0] != '-')
						f_input = argv[i+1];
					break;
				case 'm':
					if (argv[i][2] != '\0')
						month = atoi(&argv[i][2]);
					else if (i+1 < argc && argv[i+1][0] != '-')
						month = atoi(argv[i+1]);
					break;
				case 'p': print_info = 1;
					if (argv[i][2] != '\0')
						f_output = &argv[i][2];
					else if (i+1 < argc && argv[i+1][0] != '-')
						f_output = argv[i+1];
					break;
				case 's':
					if (argv[i][2] != '\0')
						sort = atoi(&argv[i][2]);
					else if (i+1 < argc && argv[i+1][0] != '-')
						sort = atoi(argv[i+1]);
					break;
				case 'd':
					if (argv[i][2] != '\0')
						t_string = &argv[i][2];
					else if (i+1 < argc && argv[i+1][0] != '-')
						t_string = argv[i+1];
			}
		}
	}
	if (help){
		printf("Temperature statistic application. Please enter key:\n\n");
		printf("-h\t\tFor help\n");
		printf("-f file_name\tReads an array of temperature data from the file file_name.\n");
		printf("\t\tWithout the -m xx option, it displays statistics for the year.\n");
		printf("-m xx\t\tDisplays statistics for xx month.\n");
		printf("-p\t\tDisplays an array of temperature data.\n");
		printf("-p file_name\tWrites an array of temperature data to the file file_name.\n");
		printf("-s 1\t\tSorts the data array by date (ascending). Does not affect statistics display.\n");
		printf("\t\tFor reverse sorting: -s 2.\n");
		printf("-d t_string\tDeleting records using the template: \"YxxxxMxxDxxHxxmxxtxx\",\n");
		printf("\t\twhere Y-year, M-month, D-day, H-hour, m-minute, t-temperature.\n");
		printf("\t\tFor example, to delete records for March 2021: \"Y2021M3\".\n");
	}
	else if (f_input){
		if (AddInfo(&info, f_input)){
			if (t_string)
				printf("%d records deleted.\n", DeleteInfo(&info, t_string));
			if (sort) SortByDate(&info, sort);
			if (print_info){
				if (f_output)
					printf("\nNumber of lines written in file \"%s\": %d.\n\n", f_output, PrintInfoToFile(info, f_output));
				else
					PrintInfo(info);
			}
			if (month)
				PrintMonth(info, month);
			else
				PrintYear(info);
		}
	}
	else if (month || print_info || sort || t_string)
		printf("No data file specified.\n");
	else
		printf("Temperature statistic application. To display help, add the key -h.\n");
	return 0;
}
