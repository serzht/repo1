#include <stdio.h>
#include <stdint.h>
#include "temp_api.h"

int AddInfo(sensor *info, char *filename)
{
	int number=0;
	FILE *f = fopen(filename, "r");
	if (f)
	{
		
	}
	else
		printf("\nCannot open file %s.\n", filename);
    return number;
}

void AddRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].hour = hour;
	info[number].minute = minute;
	info[number].t = t;
}

void PrintYear(sensor *info, int number)
{
	printf("PrintYear\n");
}

void PrintMonth(sensor *info, int number, uint8_t month)
{
	printf("PrintMonth\n");
}

float MonthAvg(sensor *info, int number, uint8_t month)
{
	float temp_avg=0.0;
	return temp_avg;
}

int8_t MonthMax(sensor *info, int number, uint8_t month)
{
	int8_t t_max=0;
	return t_max;
}

int8_t MonthMin(sensor *info, int number, uint8_t month)
{
	int8_t t_min=0;
	return t_min;
}

float YearAvg(sensor *info, int number)
{
	float t_avg=0.0;
	return t_avg;
}

int8_t YearMax(sensor *info, int number)
{
	int8_t t_max=0;
	return t_max;
}

int8_t YearMin(sensor *info, int number)
{
	int8_t t_min=0;
	return t_min;
}

