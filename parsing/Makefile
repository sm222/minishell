NAME = parsing.a

SRC = utils.c \
	  file.c \
	  main.c \
	  array.c \
	  replace.c \
	  redirect.c \
	  redi_utils.c

CC = clang
CFLAGS = -Wall -Wextra -Werror

LIB = ../lib/lib_ft
LIBNAME = libft.a

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB)/$(LIBNAME) -g

test: libft
	clang -Wall -Wextra -Werror test.c $(LIB)/$(LIBNAME)

fclean: 
	rm $(NAME)

re: fclean all

libft:
	$(MAKE) -C  $(LIB)

.PHONY: all test libft
