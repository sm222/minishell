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

RL_DIR			=	readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

#

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g -D MINI_BIN=$(BIN_DIR) -D CONPILE_DIR=$(PWD)
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
			built_in/cd/cd.c\
			built_in/pwd/pwd.c\
			built_in/echo/echo.c\
			built_in/env/ft_env.c\
			built_in/exit/ft_exit.c\
			built_in/export/export.c\
			built_in/unset/ft_unset.c\
			built_in/export/export_u.c\
			built_in/ms/ms_pwd.c\
			built_in/ms/ms.c\
			built_in/ms/ms_update.c\
			built_in/ms/ms_logic.c\
			find_git.c\
			aliace.c\

#env -i ./minishell

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)
PWD  = $(shell pwd)

ifeq ($(shell uname -s), Darwin)
    BIN_DIR = \"/Users/$(USER)/Mini_bin/\"
else
    BIN_DIR = \"/home/$(USER)/Mini_bin/\"
endif


all: libft builtin exe parse doc $(NAME)
	@printf "$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)\n"
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) readline/ -lreadline -lhistory -lncurses \
	$(RL_DIR)$(RL_H) $(RL_DIR)$(RL_L) $(EXECUTION_DIR)$(EXECUTION_LIB) \
	$(PARSE_DIR)$(PARSE_LIB) $(HERE_DOC_DIR)$(HERE_DOC_LIB) -o $(NAME)
libft:
	@printf "$(GRN)making libft$(WHT)\n"
	@make -C $(LIBFT_DIR)

parse:
	@printf "$(GRN)making parsing$(WHT)\n"
	@make -C parsing

builtin:
	@printf "$(GRN)making builtin$(WHT)\n"
	@make -C built_in

exe:
	@printf "$(GRN)making execution$(WHT)\n"
	@make -C $(EXECUTION_DIR)

doc:
	@printf "$(GRN)making doc$(WHT)\n"
	@make -C $(HERE_DOC_DIR)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell 

readline:
	cd readline && ./configure && $(MAKE)

rm_readline:
	cd readline && make distclean



#https://github.com/sm222/C_tools

# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C built_in         clean
	@make -C $(LIBFT_DIR)     clean
	@make -C $(HERE_DOC_DIR)  clean
	@make -C $(EXECUTION_DIR) clean
	@make -C parsing		  clean
	@echo $(shell clear)
	@printf "$(GRN)clean *.o$(RESET)\n"

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@$(RM) -fr minishell.dSYM 
	@make -C built_in         fclean
	@make -C $(LIBFT_DIR)     fclean
	@make -C $(HERE_DOC_DIR)  fclean
	@make -C $(EXECUTION_DIR) fclean
	@make -C parsing		  fclean
	@echo $(shell clear)
	@printf "$(GRN)clean all$(RESET)\n"

run: all
	@./$(NAME)

mc: all clean

re: fclean all

cp:
	cp supp.txt /tmp

norm:
	norminette *.c parsing here_doc/ signal/ execution include built_in lib

.PHONY: all libft run mc readline rm_readline
