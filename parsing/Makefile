NAME = parsing.a

SRC = utils.c \
	  file.c \
	  pipe.c \
	  main.c \
	  array.c \
	  verify.c \
	  quotes.c \
	  fragment.c \
	  redirect.c \
	  redi_utils.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror

LIB = ../lib/lib_ft
LIBNAME = libft.a

ARCHIVE = ar -rcs $(NAME) $(OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	@cp $(LIB)/$(LIBNAME) $(NAME)
	@$(ARCHIVE)

test: libft
	clang -Wall -Wextra -Werror $(SRC) todo.c $(LIB)/$(LIBNAME) -l readline -g

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all test libft fclean
