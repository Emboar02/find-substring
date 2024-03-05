CC = gcc
CFLAGS = -Wall -fsanitize=address
all:
	$(CC) $(CFLAGS) -o p05 p05.c
clean:
	rm -f p05
