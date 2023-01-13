CC := gcc
CFILE := main.c
CSTD := -std=c18
COPS := -O0
CWARN := -Wall -Wextra -Wconversion -Wpedantic -Werror
CDEF :=
CLIBS :=
CFLAGS := $(CSTD) $(COPS) $(CWARN) $(CDEF) $(CLIBS)
CDEBUG := -g -fsanitize=address
BIN := tests.out

.PHONY: tests debug-tests sanitize-tests

tests: gen-tests
	./$(BIN)

gen-tests:
	$(CC) $(CFILE) -o $(BIN) $(CFLAGS)

sanitize-tests: gen-debug-tests
	./$(BIN)

debug-tests: gen-debug-tests
	gdb ./$(BIN)

gen-debug-tests:
	$(CC) $(CFILE) -o $(BIN) $(CDEBUG) $(CFLAGS)
