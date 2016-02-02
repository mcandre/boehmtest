CC=clang
FLAGS=-O2 -Wall -Wextra -Wmost -Weverything

BIN=bin/boehmtest

all: test

test: $(BIN)
	./$(BIN)

$(BIN): boehmtest.c
	mkdir -p bin/
	$(CC) $(FLAGS) -o $(BIN) boehmtest.c -lgc

cppcheck:
	cppcheck --quiet --enable=all --suppressions $$HOME/suppressions.cfg .

splint:
	find . -type f -name '*.[ch]' -exec splint {} \;

vera++:
	find . -type f -name '*.cpp' -o -name '*.[ch]' -exec vera++ -s {} \;

infer: clean
	infer -- make

lint: cppcheck splint vera++ infer

valgrind: $(BIN)
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes ./$(BIN)

clean:
	-rm -rf bin/
