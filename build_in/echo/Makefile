RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RESET	=	"\x1B[0m"
CLE 	=	\e[1;1H\e[2J

NAME	=	echo

LIBFT		=	libft.a
LIBFT_DIR	=	../../lib/lib_ft/


# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	echo.c


OBJS	=	$(SRCS:.c=.o)


all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

# Removes objects
clean:
	@$(RM) $(OBJS)
	@echo $(shell clear)
	@echo -n $(GRN)
	@echo clean *.o$(RESET)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo $(shell clear)$(GRN)clean all$(RESET)


run: all
	@./$(NAME) -n test rrr


mc: all clean



# Removes objects and executables and remakes
re: fclean all

.PHONY: all