#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct sensor
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t t;
} sensor;

typedef struct info_node
{
	sensor data;
	struct info_node *next;
	struct info_node *prev;
} info_node;

enum Direction {forward=1, reverse};

int AddInfo(info_node **info, char *f_input);
int AddRecord(info_node **info, sensor data);
int DeleteInfo(info_node **info, char *t_string);
void DeleteRecord(info_node **info, info_node *node);
int MatchTemplate(sensor *a, sensor *template);
void PrintInfo(info_node *info);
int PrintInfoToFile(info_node *info, char *f_output);
int8_t MonthMin(info_node *info, uint8_t month);
int8_t MonthMax(info_node *info, uint8_t month);
int8_t MonthAvg(info_node *info, uint8_t month);
void PrintMonth(info_node *info, uint8_t month);
int8_t YearMin(info_node *info);
int8_t YearMax(info_node *info);
float YearAvg(info_node *info);
void PrintYear(info_node *info);
void SortByDate(info_node **info, enum Direction n);
int CompareF(uint32_t *a, uint32_t *b);
int CompareR(uint32_t *a, uint32_t *b);
int CmpDate(sensor *a, sensor *b);
#endif
