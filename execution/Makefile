NAME	=	execution.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	build_cmd.c\
			exe_built_in.c\
			exe_utils.c\
			find_cmd.c\
			pipe.c\
			run.c\
			run_util.c\
			token.c\
			wait_pid.c\
			err_local.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all