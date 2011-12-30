EXECUTABLE = boehmtest

all: boehmtest.c
	gcc -o $(EXECUTABLE) boehmtest.c -I/usr/include/gc -lgc

clean:
	-rm $(EXECUTABLE)
