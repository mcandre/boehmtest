EXECUTABLE = boehmtest

all: boehmtest.c
	gcc -o $(EXECUTABLE) boehmtest.c -lgc

clean:
	-rm $(EXECUTABLE)