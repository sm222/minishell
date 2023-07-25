all: libft
	clang -Wall -Wextra -Werror todo.c libft/libft.a 

libft:
	$(MAKE) -C libft/

.PHONY: all libft
