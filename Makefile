all: printf
	clang -Wall -Wextra -Werror todo.c printf/libftprintf.a 

test: printf
	clang -Wall -Wextra -Werror test.c printf/libftprintf.a

red: libft
	clang -Wall -Wextra -Werror replace.c libft/libft.a

libft:
	$(MAKE) -C libft/

printf:
	$(MAKE) -C printf/

clone:
	git clone https://github.com/0cculus/libft
	git clone https://github.com/0cculus/printf

.PHONY: all test libft
