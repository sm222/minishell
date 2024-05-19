RED				=	\x1B[31m
GRN				=	\x1B[32m
YEL				=	\x1B[33m
BLU				=	\x1B[34m
MAG				=	\x1B[35m
CYN				=	\x1B[36m
WHT				=	\x1B[37m
RESET			=	\x1B[0m
CLE 			=	\e[1;1H\e[2J

NAME			=	minishell

LIBFT			=	libft.a
LIBFT_DIR		=	lib/lib_ft/

EXECUTION_LIB	=	execution.a
EXECUTION_DIR	=	execution/

HERE_DOC_LIB	=	here_doc.a
HERE_DOC_DIR	=	here_doc/

PARSE_LIB		=	parsing.a
PARSE_DIR		=	parsing/

RL_DIR			=	include/readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

#		config		#

version = \"$(shell cat .config/version)\"

USER = $(shell whoami)
PWD  = \"$(shell pwd)\"

ifeq ($(shell uname -s), Darwin)
    BIN_DIR = \"/Users/$(USER)/Mini_bin/\"
    L = "
else
    BIN_DIR = \"/home/$(USER)/Mini_bin/\"
    L = '
endif


ifeq ($(shell test -d /Users/$(USER)/.brew/opt/readline; echo $$?), 0)
	BREW = .brew
else ifeq ($(shell test -d /Users/$(USER)/homebrew/opt/readline; echo $$?), 0)
	BREW = homebrew
endif

TEST = $(shell test -e include/readline/libreadline.a ; echo "$$?")


# Compiler and flags
CC				=	gcc
FLAGS_SHELL		=	-D MINI_BIN=$(BIN_DIR) -D CONPILE_DIR=$(PWD) -D V_MINI=$(version)
CFLAGS			=	-Wall -Werror -Wextra -g -fno-common $(FLAGS_SHELL)
#-fsanitize=address
RM				=	rm -f

# Sources are all .c files
SRCS	=	main.c\
			env.c\
			set_pec.c\
			main_ft.c\
			main_logo.c\
			converter.c\
			free_shell.c\
			include/err.c\
			converter_ft.c\
			signal/signal.c\
			export_main.c\
			built_in/cd/cd.c\
			built_in/pwd/pwd.c\
			built_in/echo/echo.c\
			built_in/env/ft_env.c\
			built_in/exit/ft_exit.c\
			built_in/export/export.c\
			built_in/unset/ft_unset.c\
			built_in/export/export_u.c\
			built_in/ms/ms_update.c\
			built_in/ms/ms_logic.c\
			built_in/ms/ms_jump.c\
			built_in/ms/ms_pwd.c\
			built_in/ms/ms.c\
			find_git.c\
			built_in/alias/alias.c\
			main_pwd.c\
			alias.c\

#env -i ./minishell

OBJS	=	$(SRCS:.c=.o)

all: rl libft builtin exe parse doc $(NAME)
	@printf $(L)$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)\n$(L)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -L include/readline -l readline -l ncurses \
	$(RL_DIR)$(RL_H) $(RL_DIR)$(RL_L) $(EXECUTION_DIR)$(EXECUTION_LIB) \
	$(PARSE_DIR)$(PARSE_LIB) $(HERE_DOC_DIR)$(HERE_DOC_LIB) -o $(NAME)

rl:
	@if test $(TEST) = 1 ; then \
		cd include/readline && ./configure && make ; \
	else \
		echo readline all ready make ; sleep 1; \
	fi

libft:
	@printf $(L)$(GRN)making libft$(WHT)\n$(L)
	@make -s -C $(LIBFT_DIR)
	@printf $(L)$(GRN)libft done$(WHT)\n$(L)

parse:
	@printf $(L)$(GRN)making parsing$(WHT)\n$(L)
	@make -s -C parsing
	@printf $(L)$(GRN)parsing done$(WHT)\n$(L)

builtin:
	@printf $(L)$(GRN)making builtin$(WHT)\n$(L)
	@make -s -C built_in
	@printf $(L)$(GRN)builtin done$(WHT)\n$(L)

exe:
	@printf $(L)$(GRN)making execution$(WHT)\n$(L)
	@make -s -C $(EXECUTION_DIR)
	@printf $(L)$(GRN)execution done$(WHT)\n$(L)

doc:
	@printf $(L)$(GRN)making doc$(WHT)\n$(L)
	@make -s -C $(HERE_DOC_DIR)
	@printf $(L)$(GRN)doc done$(WHT)\n$(L)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell 

readline:
	cd include/readline && ./configure && $(MAKE)

rm_readline:
	cd include/readline && make distclean

config:
	cp .config/.msrc $$HOME

rm_config:
	rm $$HOME/.msrc

#https://github.com/sm222/C_tools

# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C built_in         clean
	@make -C $(LIBFT_DIR)     clean
	@make -C $(HERE_DOC_DIR)  clean
	@make -C $(EXECUTION_DIR) clean
	@make -C parsing          clean
	@printf $(L)$(GRN)clean *.o$(RESET)\n$(L)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@$(RM) -fr minishell.dSYM 
	@make -C built_in         fclean
	@make -C $(LIBFT_DIR)     fclean
	@make -C $(HERE_DOC_DIR)  fclean
	@make -C $(EXECUTION_DIR) fclean
	@make -C parsing          fclean
	@printf $(L)$(GRN)clean all$(RESET)\n$(L)

ffclean: rm_readline fclean

run: all
	@./$(NAME)

mc: all clean

re: fclean all

cp:
	cp supp.txt /tmp

norm:
	norminette *.c parsing here_doc/ signal/ execution include built_in lib

exp:
	echo 'export CPPFLAGS="-I/Users/$(USER)/$(BREW)/opt/readline/include"' >> /Users/$(USER)/.zshrc
	echo 'export LDFLAGS="-L/Users/$(USER)/$(BREW)/opt/readline/lib"' >> /Users/$(USER)/.zshrc

.PHONY: all libft run mc readline rm_readline
