NAME	=	execution.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	build_cmd.c\
			run.c\
			find_cmd.c\
			wait_pid.c\
			token.c\
			pipe.c\
			exe_build_in.c\
			run_util.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)


fclean: clean
	@$(RM) $(NAME)

re: fclean all