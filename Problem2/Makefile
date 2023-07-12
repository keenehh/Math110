CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra -g
LDFLAGS = -lm

all: prime

prime: prime.o
	$(CC) prime.o -o prime $(LDFLAGS)

prime.o: prime.c
	$(CC) $(CFLAGS) -c prime.c

clean:
	rm -f *.o prime

format:
	clang-format -i -style=file *.[ch]
