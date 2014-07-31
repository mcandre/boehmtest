CC=clang
FLAGS=-O2 -Wall -Wextra -Wmost -Weverything

BIN=boehmtest

all: test

test: $(BIN)
	./$(BIN)

$(BIN): boehmtest.c
	$(CC) $(FLAGS) -o $(BIN) boehmtest.c -lgc

cppcheck:
	cppcheck --quiet --enable=all --suppressions $$HOME/suppressions.cfg .

splint:
	find . -type f -name '*.[ch]' -exec splint {} \;

vera++:
	find . -type f -name '*.cpp' -o -name '*.[ch]' -exec vera++ -s {} \;

lint: cppcheck splint vera++

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes ./$(BIN)

clean:
	-rm boehmtest
	-rm *.exe
