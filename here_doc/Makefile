NAME	=	here_doc.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

RL_DIR			=	../readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	here_doc.c\
			make_here_doc.c


OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS) $(RL_DIR)$(RL_H) $(RL_DIR)$(RL_L)

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

test:
	gcc main.c here_doc.a -l readline -l ncurses

re: fclean all