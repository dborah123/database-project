CFLAGS = -g -Wall -pedantic
CFLAGS_T=-g -Wall -pedantic -pthread

.PHONY: all
all: repl

repl: repl.c
	echo "Compiling repl.c"
	gcc $(CFLAGS_T) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o repl