#include "temp_functions.h"

#define SIZE 4096		//размер буфера чтения fread (4096 байт - размер по умолчанию собственного буфера этой ф-ции)

int AddRecord(info_node **info, sensor data)
{
	if (data.year && data.month && data.day && data.year < 10000 && data.month < 13 && data.day < 32 && data.hour < 25 && data.minute < 60 ){
		info_node *p = malloc(sizeof(info_node));
		if (p){
			p->data = data;
			if (*info){
				(*info)->prev->next = p;
				p->prev = (*info)->prev;
				p->next = *info;
				(*info)->prev = p;
			}
			else{
				*info = p;
				(*info)->prev = *info;
				(*info)->next = *info;
			}
			return 1;
		}
		else
			printf("Failed to allocate memory.\n");
	}
	return 0;
}

int AddInfo(info_node **info, char *f_input)
{
	sensor data;
	char s[SIZE], c=0;
	int numread, num, err, i, j, number=0, num_line=0;
	FILE *f = fopen(f_input, "r");
	if (f){
		j=1, err=0, num=0, data.t=0;
		while ((numread = fread(s, sizeof(char), SIZE, f))){
			for (i=0; i < numread; i++){
				c = *(s+i);
				if (c >= '0' && c <= '9')
					num = num*10 + c-0x30;
				else if (c == '-'){
					if (j == 6) data.t=-1;
					else err=1;
				}
				else if (c == ';'){
					switch (j){
						case 1:	data.year = num; break;
						case 2: data.month = num; break;
						case 3: data.day = num; break;
						case 4: data.hour = num; break;
						case 5: data.minute = num;
					}
					num=0; j++;
				}
				else if (c == '\n'){
					num_line++;
					data.t = data.t < 0 ? data.t*num : num;
					if (err || !AddRecord(info, data))
						printf("Line %d contains an error and will be skipped.\n", num_line);
					else
						number++;
					num=0, j=1, err=0, data.t=0;
				}
				else
					if (c != ' ') err = 1;
			}
		}
		if (ferror(f)){
			printf("There was an error reading the file.\n");
			fclose(f);
			return 0;
		}
		else if (j > 1){
			num_line++;
			data.t = data.t < 0 ? data.t*num : num;
			if (err || !AddRecord(info, data))
				printf("Line %d contains an error and will be skipped.\n", num_line);
			else
				number++;
		}
		fclose(f);
	}
	else{
		printf("\nCannot open file '%s'.\n", f_input);
		return 0;
	}
	return number;
}

void DeleteRecord(info_node **info, info_node *node)
{
	if (node->next != node){
		if (node == *info) *info = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		free(node);
	}
	else{
		free(node);
		*info = NULL;
	}
}

int DeleteInfo(info_node **info, char *t_string)
{	//t_string = "Y2021M3D1H1m1t0";
	sensor template={10000,127,127,127,127,127};
	int num, counter=0, a=0, c, minus, str_len = strlen(t_string), answer_yes=0, forcing=0, flag;
	for (int i=0; i <= str_len; i++){
		c = *(t_string + i);
		if (c == 'Y' || c == 'M' || c == 'D' || c == 'H' || c == 'm' || c == 't' || c == '\0'){
			if (a){
				switch (a){
					case 'Y': if (num > -1) template.year = num; break;
					case 'M': if (num > -1) template.month = num; break;
					case 'D': if (num > -1) template.day = num; break;
					case 'H': if (num > -1) template.hour = num; break;
					case 'm': if (num > -1) template.minute = num; break;
					case 't': if (num > -1) template.t = minus ? -1*num : num;
				}
			}
			a = c; minus=0; num=-1;
		}
		else if (c >= '0' && c <= '9'){
			if (num == -1) num = 0;
			num = num*10 + c-0x30;
		}
		else if (c == '-')
			minus = 1;
	}
	if (template.year == 10000 && template.month == 127 && template.day == 127 && template.hour == 127 && template.minute == 127 && template.t == 127) return 0;
	info_node *p=*info;
	if (p){
		do {
			flag=0;
			if (forcing == 0) answer_yes=0;
			if (MatchTemplate(&(p->data), &template) == 0){
				if (forcing == 0){
					printf("The following line will be deleted:\n");
					printf("year = %d, month = %d, day = %d, hour = %d, minute = %d, t = %d\n", p->data.year, p->data.month, p->data.day, p->data.hour, p->data.minute, p->data.t);
					printf("Continue? (y/n or yf/nf (f - for all):");
					while ((c=getchar()) != '\n'){
						if (c == 'y' || c == 'Y') answer_yes=1;
						if (c == 'f' || c == 'F') forcing=1;
					}
				}
				if (answer_yes){
					p = p->next;
					DeleteRecord(info, p->prev);
					if (forcing == 0) printf("Data deleted.\n");
					counter++, flag = 1;
				}
				else{
					if (forcing == 0) printf("Action canceled.\n");
					p = p->next;
				}
			}
			else
				p = p->next;
		} while ((p != *info || flag) && *info);
	}
	return counter;
}

int MatchTemplate(sensor *a, sensor *template)							//Функция сравнения с шаблоном для удаления записей
{
	if (template->year < 10000 && (a->year - template->year))
		return a->year - template->year;
	else if (template->month < 127 && (a->month - template->month))
		return a->month - template->month;
	else if (template->day < 127 && (a->day - template->day))
		return a->day - template->day;
	else if (template->hour < 127 && (a->hour - template->hour))
		return a->hour - template->hour;
	else if (template->minute < 127 && (a->minute - template->minute))
		return a->minute - template->minute;
	else if (template->t < 127 && (a->t - template->t))
		return a->t - template->t;
	return 0;
}

void PrintInfo(info_node *info)
{
	int i=0;
	info_node *p=info;
	if (p){
		printf("======================================\n");
		printf("     # Year Month Day Hour Minute Temp\n");
		do {
			printf("%6u %4u %4u %4u %3u %5u %6d\n", i++, p->data.year, p->data.month, p->data.day, p->data.hour, p->data.minute, p->data.t);
			p = p->next;
		} while (p != info);
		printf("======================================\n");
	}
}

int8_t MonthMin(info_node *info, uint8_t month)
{
	int8_t t_min=0, flag=1;
	info_node *p=info;
	if (p){
		do{
			if (p->data.month == month){
				if (flag){
					t_min = p->data.t;
					flag = 0;
				}
				if (t_min > p->data.t) t_min = p->data.t;
			}
			p = p->next;
		} while (p != info);
	}
	return t_min;
}

int8_t MonthMax(info_node *info, uint8_t month)
{
	int8_t t_max=0, flag=1;
	info_node *p=info;
	if (p){
		do{
			if (p->data.month == month){
				if (flag){
					t_max = p->data.t;
					flag = 0;
				}
				if (t_max < p->data.t) t_max = p->data.t;
			}
			p = p->next;
		} while (p != info);
	}
	return t_max;
}

int8_t MonthAvg(info_node *info, uint8_t month)
{
	int sum=0, counter=0;
	info_node *p=info;
	if (p){
		do{
			if (p->data.month == month){
				sum += p->data.t;
				counter++;
			}
			p = p->next;
		} while (p != info);
	}

	return counter ? (int8_t)(sum/counter) : 0;
}

void PrintMonth(info_node *info, uint8_t month)
{
	int counter=0, year=0;
	info_node *p=info;
	if (p){
		printf("==============================================\n");
		printf(" Year Month NuValue MonthAvg MonthMax MonthMin\n");
		do{
			if (p->data.month == month){
				if (year == 0) year = p->data.year;
				counter++;
			}
			p = p->next;
		} while (p != info);
	}
	printf(" %4u %4u %7u %6d %8d %8d\n", year, month, counter, MonthAvg(info, month), MonthMax(info, month), MonthMin(info, month));
	printf("==============================================\n");
}

int8_t YearMin(info_node *info)
{
	int8_t t_min=0;
	info_node *p=info;
	if (p){
		t_min = p->data.t;
		do{
			if (t_min > p->data.t)	t_min = p->data.t;
			p = p->next;
		} while (p != info);
	}
	return t_min;
}

int8_t YearMax(info_node *info)
{
	int8_t t_max=0;
	info_node *p=info;
	if (p){
		t_max = p->data.t;
		do{
			if (t_max < p->data.t)	t_max = p->data.t;
			p = p->next;
		} while (p != info);
	}
	return t_max;
}

float YearAvg(info_node *info)
{
	int months[13]={0}, sum=0, counter=0;
	info_node *p=info;
	if (p){
		do{
			if (*(months + p->data.month) == 0){
				*(months + p->data.month) = 1;
				sum += MonthAvg(info, p->data.month);
				counter++;
			}
			p = p->next;
		} while (p != info);
	}
	return counter ? (float)sum / counter : 0;
}

void PrintYear(info_node *info)
{
	int months[13]={0}, years[13]={0};
	info_node *p=info;
	if (p){
		printf("================================================\n");
		printf(" # Year Month NuValue MonthAvg MonthMax MonthMin\n");
		do{
			(*(months + p->data.month))++;
			if (*(years + p->data.month) == 0) *(years + p->data.month) = p->data.year;
			p = p->next;
		} while (p != info);
		for (int i=1, j=1; i < 13; i++)
			if (*(months + i)) printf("%2u %4u %4u %7u %6d %8d %8d\n", j++, *(years + i), i, *(months + i), MonthAvg(info, i), MonthMax(info, i), MonthMin(info, i));
		printf("Year statistic: average is %4.2f, max is %d, min is %d\n", YearAvg(info), YearMax(info), YearMin(info));
		printf("================================================\n");
	}
}

int PrintInfoToFile(info_node *info, char *f_output)
{
	int number_rows=0;
	info_node *p=info;
	FILE *f=NULL;
	if (p){
		f = fopen(f_output, "w");
		if (f){
			do{
				fprintf(f, "%04u;%02u;%02u;%02u;%02u;%d\n", p->data.year, p->data.month, p->data.day, p->data.hour, p->data.minute, p->data.t);
				number_rows++;
				p = p->next;
			} while (p != info);
		}
		else{
			printf("\nCannot open file '%s'.\n", f_output);
			return 0;
		}
		fclose(f);
	}
	return number_rows;
}

void SortByDate(info_node **info, enum Direction n)	 					//Гибридный механизм сортировки. Сначала сортируем массив arr структур link библиотечной ф-цией qsort.
{																		//Затем настраиваем связи между элементами прямо в отсортированном массиве структур.
	uint32_t number=0, i;
	link *arr=NULL;
	info_node *p=*info;
	if (p && (p != p->next)){											//Условие отсеивает списки с числом элементов < 2
		do{
			number++; p = p->next;
		} while (p != *info);
		arr = malloc(number*sizeof(link));
		if(arr){
			p=*info;
			for (i=0; i < number; i++){
				(arr + i)->num_date = p->data.year << 20 | p->data.month << 16 | p->data.day << 11 | p->data.hour << 6 | p->data.minute;
				(arr + i)->p_info_node = p;
				p = p->next;
			}
			if (n == forward)
				qsort(arr, number, sizeof(link), (int(*) (const void *, const void *)) CompareF);
			else if (n == reverse)
				qsort(arr, number, sizeof(link), (int(*) (const void *, const void *)) CompareR);
			*info = arr->p_info_node;
			arr->p_info_node->prev = (arr + number-1)->p_info_node;						//Сразу оформляем первый и последний элементы,
			arr->p_info_node->next = (arr + 1)->p_info_node;							//связывая их между собой,
			(arr + number-1)->p_info_node->prev = (arr + number-2)->p_info_node;		//а также всего одной связью
			(arr + number-1)->p_info_node->next = arr->p_info_node;						//с соседями справа и слева.
			for (i=1; i < number-1; i++)												//В цикле работаем с элементами, начиная со 2-го по предпоследний,
			{																			//для каждого настраивая по одной связи справа и слева (next и prev)
				(arr + i)->p_info_node->prev = (arr + i-1)->p_info_node;
				(arr + i)->p_info_node->next = (arr + i+1)->p_info_node;
			}
			free(arr);
		}
		else
			printf("Error allocating memory for sorting.\n");
	}
}

int CompareF(link *a, link *b)
{
	return a->num_date - b->num_date;
}

int CompareR(link *a, link *b)
{
	return b->num_date - a->num_date;
}
