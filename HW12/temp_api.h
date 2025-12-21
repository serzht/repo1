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

enum Direction {forward, reverse};

int AddInfo(sensor **info, char *filename);
void AddRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);
int DeleteRecord(sensor *info, int number, uint16_t year,uint8_t month, uint8_t day, uint8_t hour, uint8_t minute);
void PrintInfo(sensor *info, int number);
void PrintYear(sensor *info, int number);
void PrintMonth(sensor *info, int number, uint8_t month);
int8_t MonthAvg(sensor *info, int number, uint8_t month);
int8_t MonthMax(sensor *info, int number, uint8_t month);
int8_t MonthMin(sensor *info, int number, uint8_t month);
float YearAvg(sensor *info, int number);
int8_t YearMax(sensor *info, int number);
int8_t YearMin(sensor *info, int number);
void SortByDate(sensor *info, int number, enum Direction n);
int CompareF(sensor *a, sensor *b);
int CompareR(sensor *b, sensor *a);
#endif
