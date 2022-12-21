CC := gcc
CFILE := main.c
CSTD := -std=c18
COPS := -O0
CWARN := -Wall -Wextra -Werror -pedantic
CLIBS :=
CFLAGS := $(CLIBS) $(CSTD) $(COPS) $(CWARN)
BIN := tests.out

.PHONY: tests

tests: gen-tests
	./$(BIN)

gen-tests:
	$(CC) $(CFILE) -o $(BIN) $(CFLAGS)
