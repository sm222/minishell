USER = $(shell whoami)

ifeq ($(shell uname -s), Darwin)
    BIN_DIR = /Users/$(USER)/Mini_bin/
else
    BIN_DIR = /home/$(USER)/Mini_bin/
endif

NAME	=	$(BIN_DIR)ft_echo

LIBFT		=	libft.a
LIBFT_DIR	=	../../lib/lib_ft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

# Sources are all .c files
SRCS	=	echo.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)

run: all
	@./$(NAME) -n test rrr

mc: all clean

# Removes objects and executables and remakes
re: fclean all

.PHONY: all