CC:=gcc
CFLAGS:=-O -Wall -Wextra

OUTPUT:=build/ui0118.a

#SRCS=$(wildcard src/*.c) $(wildcard src/widget/*.c)
SRCS:=$(shell find src -name '*.c')
OBJS:=$(patsubst src/%.c,build/%.o,$(SRCS)) #ui0118.o ui0118_texture.o ui0118_widget.o ui0118_util.o ui0118_window.o

build: $(OUTPUT)

test: build test/test.c
	$(CC) $(CFLAGS) -lSDL2 -lSDL2_image -lcjson -g test/test.c build/ui0118.a -o test/a.out

clean:
	rm -f $(wildcard build/*.o)
	rm -f $(wildcard build/*/*.o)
	rm -f test/a.out

clean_all: clean
	rm -f build/ui0118.a

src/%.c:: src/%.h src/ui0118_common.h

src/ui0118_texture.c: $(wildcard textures/*)
	./make_textures.sh

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJS)
	ar rcs $@ $^

.PHONY: build test clean clean_all
