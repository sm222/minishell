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

RL_DIR			=	readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

#tools
C_TOOL			=	C_tools/C_tool.a
C_TOOL_DIR		=	C_tools/
#

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
RM				=	rm -f

# Sources are all .c files
SRCS	=	main.c\
			env.c\
			main_logo.c\
			include/err.c\
			built_in/cd/cd.c\
			built_in/pwd/pwd.c\
			built_in/echo/echo.c\
			built_in/env/ft_env.c\
			built_in/exit/ft_exit.c\
			built_in/export/export.c\
			built_in/unset/ft_unset.c\

#env -i ./minishell

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)

all: tools libft builtin exe $(NAME)
	@printf "$(CYN) \n\n			correction is made by $(USER)\n\n  $(RESET)"
	
$(NAME): $(OBJS) $(C_TOOL)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -l readline -l ncurses \
	$(RL_DIR)$(RL_H) $(RL_DIR)$(RL_L) $(C_TOOL) $(EXECUTION_DIR)$(EXECUTION_LIB) \
	-o $(NAME)

libft:
	@printf "$(GRN)making libft$(WHT)\n"
	@$(MAKE) -C $(LIBFT_DIR)

builtin:
	@printf "$(GRN)making buildin$(WHT)\n"
	@make -C built_in

exe:
	@printf "$(GRN)execution buildin$(WHT)\n"
	@make -C $(EXECUTION_DIR)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=supp.txt ./minishell 

#https://github.com/sm222/C_tools
tools:
	@make -C $(C_TOOL_DIR)
# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(EXECUTION_DIR) clean
	@make -C $(C_TOOL_DIR) clean
	@make -C built_in clean
	@echo $(shell clear)
	@printf "$(GRN)clean *.o$(RESET)\n"

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@make -C built_in fclean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(C_TOOL_DIR) fclean
	@make -C $(EXECUTION_DIR) fclean
	@echo $(shell clear)
	@printf "$(GRN)clean all$(RESET)\n"

run: all
	@./$(NAME)

mc: all clean

# Removes objects and executables and remakes
re: fclean all

.PHONY: all libft