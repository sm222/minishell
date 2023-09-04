NAME = parsing.a

SRC = utils.c \
	  file.c \
	  array.c \
	  redirect.c \
	  redi_utils.c \

CC = clang
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

test: libft
	clang -Wall -Wextra -Werror test.c printf/libftprintf.a

libft:
	$(MAKE) -C printf/

.PHONY: all test libft
