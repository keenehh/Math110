CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra -g

all: linear

linear: linear.o
	$(CC) linear.o -o linear

linear.o: linear.c
	$(CC) $(CFLAGS) -c linear.c

clean:
	rm -f *.o linear

format:
	clang-format -i -style=file *.[ch]


#testing stuff