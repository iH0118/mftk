CC:=gcc
CFLAGS:=-O -Wall -Wextra

OUTPUT:=build/mftk.a
SRCS:=$(shell find src -name '*.c')
OBJS:=$(patsubst src/%.c,build/%.o,$(SRCS))

build: $(OUTPUT)

test/a.out: test/test.c $(OUTPUT)
	$(CC) $(CFLAGS) -lSDL2 -lSDL2_image -lcjson -g $^ -o $@

test: test/a.out

test_run: test
	@cd test; ./a.out

clean:
	rm -f $(wildcard build/*.o)
	rm -f $(wildcard build/*/*.o)
	rm -f test/a.out

clean_all: clean
	rm -f build/mftk.a

src/%.c:: src/%.h src/mftk_common.h

src/mftk_texture.c: $(wildcard textures/*)
	util/make_textures.sh

build/%.o: src/%.c
	@mkdir -p build build/widget
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTPUT): $(OBJS)
	ar rcs $@ $^

.PHONY: build test test_run clean clean_all
