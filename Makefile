all: boehmtest.c
	gcc -o boehmtest boehmtest.c -lgc

clean:
	-rm boehmtest
	-rm boehmtest.exe