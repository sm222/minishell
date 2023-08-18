all: libft
	clang -Wall -Wextra -Werror todo.c printf/libftprintf.a 

test: libft
	clang -Wall -Wextra -Werror test.c printf/libftprintf.a

libft:
	$(MAKE) -C printf/

.PHONY: all test libft
