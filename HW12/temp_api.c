#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "temp_api.h"

#define SIZE 4096		//размер буфера чтения fread (4096 байт - размер по умолчанию собственного буфера этой ф-ции)

extern int size_info;	//реальный размер info

int AddInfo(sensor **info, char *filename)
{
	uint16_t year;
	uint8_t month, day, hour, minute;
	int8_t t;
	char s[SIZE], c=0;
	int number=0, numread, num, err, i, j;
	FILE *f = fopen(filename, "r");
	if (f) {
		
		for (i=2; c >= 0;)
			if ((c=fgetc(f)) == '\n') i++;
		size_info = i + 5;
		*info = (sensor *)calloc(size_info, sizeof(sensor));
		if (*info == NULL) {
			printf("Failed to allocate memory\n");
			fclose(f);
			return 0;
		}
		rewind(f);

		j=1, err=0, num=0, t=0;
		while ((numread = fread(s, sizeof(char), SIZE, f)))	{
			for (i=0; i < numread; i++)
				switch (*(s+i))	{
					case '0' ... '9':
						num = num*10 + *(s+i)-0x30;
						break;
					case '-':
						if (j == 6) t=-1;
						break;
					case ';':
						switch (j) {
							case 1:	if (num < 10000) year = (uint16_t) num; else err = 1; break;
							case 2: if (num < 13) month = (uint8_t) num; else err = 1; break;
							case 3: if (num < 32) day = (uint8_t) num; else err = 1; break;
							case 4: if (num < 25) hour = (uint8_t) num; else err = 1; break;
							case 5: if (num < 60) minute = (uint8_t) num; else err = 1;
						}
						num=0; j++; break;
					case '\n':
						t = t < 0 ? t*num : num;
						if (!err)
							AddRecord(*info, number++, year, month, day, hour, minute, t);
						num=0, j=1, err=0, t=0; break;
					default:
						if (*(s+i) == ' ' && num == 0) break;
						err = 1;
				}
		}
		if (ferror(f)) {
			printf("There was an error reading the file.\n");
			if (info) {free(info), info = NULL;}
			fclose(f);
			return 0;
		}
		else if (j > 1) {
			t = t < 0 ? t*num : num;
			if (!err)
				AddRecord(*info, number++, year, month, day, hour, minute, t);
		}
		fclose(f);
	}
	else {
		printf("\nCannot open file '%s'.\n", filename);
		return 0;
	}
    return number;
}

void AddRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
	(info + number)->year = year;
	(info + number)->month = month;
	(info + number)->day = day;
	(info + number)->hour = hour;
	(info + number)->minute = minute;
	(info + number)->t = t;
}

void PrintInfo(sensor *info, int number)
{
	printf("======================================\n");
	printf("     # Year Month Day Hour Minute Temp\n");
	for (int i=0; i < number; i++)
		printf("%6u %4u %4u %4u %3u %5u %6d\n", i+1, (info+i)->year, (info+i)->month, (info+i)->day, (info+i)->hour, (info+i)->minute, (info+i)->t);
	printf("======================================\n");
}

void PrintYear(sensor *info, int number)
{
	int months[2][13]={0};
	printf("================================================\n");
	printf(" # Year Month NuValue MonthAvg MonthMax MonthMin\n");
	for (int i=0; i < number; i++){
		months[1][(info+i)->month]++;
		if (!months[0][(info+i)->month]) months[0][(info+i)->month] = (info+i)->year;
	}
	for (int i=1, j=1; i < 13; i++)
		if (months[1][i]) printf("%2u %4u %4u %7u %6d %8d %8d\n", j++, months[0][i], i, months[1][i], MonthAvg(info, number, i), MonthMax(info, number, i), MonthMin(info, number, i));
	printf("Year statistic: average is %4.2f, max is %d, min is %d\n", YearAvg(info, number), YearMax(info, number), YearMin(info, number));
	printf("================================================\n");
}

void PrintMonth(sensor *info, int number, uint8_t month)
{
	int num_i=0, year=0;
	printf("==============================================\n");
	printf(" Year Month NuValue MonthAvg MonthMax MonthMin\n");
	for (int i=0; i < number; i++)
		if ((info+i)->month == month)
		{
			if (year == 0) year = (info+i)->year;
			num_i++;
		}
	printf(" %4u %4u %7u %6d %8d %8d\n", year, month, num_i, MonthAvg(info, number, month), MonthMax(info, number, month), MonthMin(info, number, month));
	printf("==============================================\n");
}

int8_t MonthAvg(sensor *info, int number, uint8_t month)
{
	int sum=0, num_i=0;
	for (int i=0; i < number; i++)
		if ((info+i)->month == month) {
			sum += (info+i)->t;
			num_i++;
		}
	return num_i ? (int8_t)(sum/num_i) : 0;
}

int8_t MonthMax(sensor *info, int number, uint8_t month)
{
	int8_t t_max=0, flag=0;
	for (int i=0; i < number; i++)
		if ((info+i)->month == month) {
			if (flag) {
				if (t_max < (info+i)->t)
					t_max = (info+i)->t;
			}
			else {
				t_max = (info+i)->t;
				flag = 1;
			}
		}
	return t_max;
}

int8_t MonthMin(sensor *info, int number, uint8_t month)
{
	int8_t t_min=0, flag=0;
	for (int i=0; i < number; i++)
		if ((info+i)->month == month) {
			if (flag) {
				if (t_min > (info+i)->t)
					t_min = (info+i)->t;
			}
			else {
				t_min = (info+i)->t;
				flag = 1;
			}
		}
	return t_min;
}

float YearAvg(sensor *info, int number)
{
	
	int sum=0, months[13]={0};
	for (int i=0; i < number; i++) {
		if (*(months + (info+i)->month) == 0) *(months + (info+i)->month) = 1;
	}
	for (int i=1; i < 13; i++)
		if (*(months + i)) {
			sum += MonthAvg(info, number, i);
			(*months)++;
		}
	return *months ? (float)sum / *months : 0;
}

int8_t YearMax(sensor *info, int number)
{
	int8_t t_max=0;
	if (number) t_max = info->t;
	for (int i=1; i < number; i++)
			if (t_max < (info+i)->t)
					t_max = (info+i)->t;
	return t_max;
}

int8_t YearMin(sensor *info, int number)
{
	int8_t t_min=0;
	if (number) t_min = info->t;
	for (int i=1; i < number; i++)
			if (t_min > (info+i)->t)
					t_min = (info+i)->t;
	return t_min;
}

void SortByDate(sensor *info, int number, enum Direction n)
{
	if (n == forward) qsort(info, number, sizeof(sensor), (int(*) (const void *, const void *)) CompareF);
	else qsort(info, number, sizeof(sensor), (int(*) (const void *, const void *)) CompareR);
}

int CompareF(sensor *a, sensor *b)
{
	if (a->year != b->year)
		return a->year - b->year;
	else if (a->month != b->month)
		return a->month-b->month;
	else if (a->day != b->day)
		return a->day-b->day;
	else if (a->hour != b->hour)
		return a->hour - b->hour;
	else
		return a->minute - b->minute;
}

int CompareR(sensor *b, sensor *a)
{
	if (a->year != b->year)
		return a->year - b->year;
	else if (a->month != b->month)
		return a->month-b->month;
	else if (a->day != b->day)
		return a->day-b->day;
	else if (a->hour != b->hour)
		return a->hour - b->hour;
	else
		return a->minute - b->minute;
}

int DeleteRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute)
{
	sensor a;
	a.year = year;
	a.month = month;
	a.day = day;
	a.hour = hour;
	a.minute = minute;
	for (int i=0; i < number; i++)
		if (!CompareF(&a, info+i)){
			for (int j=i; j < number-1; j++)
				*(info+j) = *(info+j+1);
			number--; i--;
		}
	return number;
}
