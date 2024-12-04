CC = gcc
CFLAGS = -O -Wall -Wextra

all: ui0118.a clean

clean:
	rm -f *.o assets/*.c

ui0118_assets.c:
	./make_assets.sh

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

ui0118.a: ui0118.o ui0118_assets.o
	ar rcs $@ $^

.PHONY: all clean
