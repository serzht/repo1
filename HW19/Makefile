CC = gcc
CFLAGS = -std=c23 -Wall -pedantic

target = report
objects = report.o temp_functions.o

All : $(target)

$(target) : $(objects)
	$(CC) -o $(target) $(objects)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	del $(wildcard *.o)
