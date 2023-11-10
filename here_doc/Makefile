NAME	=	here_doc.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g 

RL_DIR			=	../include/readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	make_here_doc.c\
			edit_here_doc.c\
			free_here_doc.c


OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

test:
	@make
	gcc $(CFLAGS) main.c here_doc.a -l readline -l history -l ncurses

mem: test
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./a.out

re: fclean 

.PHONY: all clean fclean test re mem
