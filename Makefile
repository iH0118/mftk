CC = gcc
CFLAGS = -O -Wall -Wextra

all: ui0118.a clean

clean:
	rm -f *.o

make_textures:
	./make_textures.sh

ui0118_texture.c: textures/* make_textures

ui0118_util.c: ui0118_widget.c ui0118_util.c ui0118_window.c

ui0118_widget.c: ui0118_util.c

ui0118_window.c: ui0118_texture.c

%.c: %.h

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

ui0118.a: ui0118.o ui0118_texture.o ui0118_widget.o ui0118_util.o ui0118_window.o
	ar rcs $@ $^

.PHONY: all clean make_textures
