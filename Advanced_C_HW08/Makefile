CC = gcc
CFLAGS = -std=c23 -Wall -pedantic

target = areacalc
objects = areacalc.o

all: $(target)

$(target): $(objects)
	$(CC) -o $(target) $(objects)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(wildcard *.o) $(target)
