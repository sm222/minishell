NAME	=	/tmp/binmini/ft_cd

LIBFT		=	libft.a
LIBFT_DIR	=	../../lib/lib_ft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	cd.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

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