#ifndef TEMP_API_H
#define TEMP_API_H

typedef struct
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t t;
} sensor;

int AddInfo(sensor *info, char *filename);
void AddRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);
void PrintYear(sensor *info, int number);
void PrintMonth(sensor *info, int number, uint8_t month);
float MonthAvg(sensor *info, int number, uint8_t month);
int8_t MonthMax(sensor *info, int number, uint8_t month);
int8_t MonthMin(sensor *info, int number, uint8_t month);
float YearAvg(sensor *info, int number);
int8_t YearMax(sensor *info, int number);
int8_t YearMin(sensor *info, int number);

#endif
