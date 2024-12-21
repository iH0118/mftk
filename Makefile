CC:=gcc
CFLAGS:=-O -Wall -Wextra

OUTPUT:=build/ui0118.a

SRCS:=$(wildcard src/*.c)
OBJS:=$(patsubst src/%.c,build/%.o,$(SRCS)) #ui0118.o ui0118_texture.o ui0118_widget.o ui0118_util.o ui0118_window.o

build: $(OUTPUT)

build/:
	mkdir -p build

clean:
	rm -f $(wildcard build/*.o)

clean_all: clean
	rm -f build/ui0118.a

src/ui0118_texture.c: src/ui0118_texture.h $(wildcard textures/*) src/ui0118_common.h
	./make_textures.sh

#ui0118_util.c: ui0118_util.h ui0118_common.h

#ui0118_widget.c: ui0118_widget.h ui0118_util.c ui0118_texture.c ui0118_common.h

#ui0118_window.c: ui0118_window.h ui0118_texture.c ui0118_util.h ui0118_widget.c ui0118_common.h

src/%.c: src/%.h

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJS)
	ar rcs $@ $^

.PHONY: build clean
