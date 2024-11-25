NAME = ui0118

all: $(NAME) clean

clean:
	@rm -f *.o assets.c

fclean: 

CC = gcc
CFLAGS = -O -Wall -Wextra -Werror
#LDFLAGS = -lSDL2 -lSDL2_image

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rcs $< $@

.PHONY: all clean
