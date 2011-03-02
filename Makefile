CC = gcc
DELETE = rm
EXECUTABLE = boehmtest

all: boehmtest.c
	$(CC) -o $(EXECUTABLE) boehmtest.c -lgc

clean:
	$(DELETE) $(EXECUTABLE)