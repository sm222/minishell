USER = $(shell whoami)

ifeq ($(shell uname -s), Darwin)
    BIN_DIR = /Users/$(USER)/Mini_bin/
else
    BIN_DIR = /home/$(USER)/Mini_bin/
endif

USER_GIT = $(shell git config --get user.name)

NAME	=	$(BIN_DIR)ft_ms


LIBFT		=	libft.a
LIBFT_DIR	=	../../lib/lib_ft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g -D USER_GCC='"$(USER_GIT)"'
RM		=	rm -f

# Sources are all .c files
SRCS	=	main.c\
			ms.c\
			ms_logic.c\
			ms_pwd.c\
			ms_update.c\
			ms_jump.c


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

mc: all clean

# Removes objects and executables and remakes
re: fclean all

.PHONY: all