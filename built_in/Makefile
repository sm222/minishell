RED		=	\x1B[31m
GRN		=	\x1B[32m
YEL		=	\x1B[33m
BLU		=	\x1B[34m
MAG		=	\x1B[35m
CYN		=	\x1B[36m
WHT		=	\x1B[37m
RESET	=	\x1B[0m
CLE 	=	\e[1;1H\e[2J

all: echo pwd cd env exit
	
echo:

	@printf '$(GRN)making echo$(WHT)\n'
	@make -C echo
pwd:
	@printf '$(GRN)making pwd$(WHT)\n'
	@make -C pwd
cd:
	@printf '$(GRN)making cd$(WHT)\n'
	@make -C cd
env:
	@printf '$(GRN)making env$(WHT)\n'
	@make -C env
exit:
	@printf '$(GRN)making exit$(WHT)\n'
	@make -C exit

clean:
	@make -C echo clean
	@make -C pwd  clean
	@make -C cd   clean
	@make -C env  clean
	@make -C exit clean

fclean: clean
	@make -C echo fclean
	@make -C pwd  fclean
	@make -C cd   fclean
	@make -C env  fclean
	@make -C exit fclean

re: fclean all

.PHONY: all echo pwd cd env exit