NAME	=	here_doc.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	here_doc.c\
			make_here_doc.c


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