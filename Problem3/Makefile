CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra -g
LDFLAGS = -lm

all: system

system: system.o
	$(CC) system.o -o system $(LDFLAGS)

system.o: system.c
	$(CC) $(CFLAGS) -c system.c

clean:
	rm -f *.o system

format:
	clang-format -i -style=file *.[ch]
