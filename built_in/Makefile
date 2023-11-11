RED		=	\x1B[31m
GRN		=	\x1B[32m
YEL		=	\x1B[33m
BLU		=	\x1B[34m
MAG		=	\x1B[35m
CYN		=	\x1B[36m
WHT		=	\x1B[37m
RESET	=	\x1B[0m
CLE		=	\e[1;1H\e[2J



USER = $(shell whoami)

ifeq ($(shell uname -s), Darwin)
    BIN_DIR = /Users/$(USER)/Mini_bin/
    L = "
else
    BIN_DIR = /home/$(USER)/Mini_bin/
    L = '
endif

all: dirmake echo pwd cd env expo unset exit ms
	

dirmake:
	mkdir -p $(BIN_DIR)

echo:
	@printf $(L)$(GRN)making echo$(WHT)\n$(L)
	@make -C echo

pwd:
	@printf $(L)$(GRN)making pwd$(WHT)\n$(L)
	@make -C pwd

cd:
	@printf $(L)$(GRN)making cd$(WHT)\n$(L)
	@make -C cd

expo:
	@printf $(L)$(GRN)making export$(WHT)\n$(L)
	@make -C export

env:
	@printf $(L)$(GRN)making env$(WHT)\n$(L)
	@make -C env

unset:
	@printf $(L)$(GRN)making unset$(WHT)\n$(L)
	@make -C unset

exit:
	@printf $(L)$(GRN)making exit$(WHT)\n$(L)
	@make -C exit

ms:
	@printf $(L)$(GRN)making ms$(WHT)\n$(L)
	@make -C ms

clean:
	@make -C echo   clean
	@make -C pwd    clean
	@make -C cd     clean
	@make -C env    clean
	@make -C unset  clean
	@make -C export clean
	@make -C exit   clean
	@make -C ms     clean

fclean: clean
	@make -C echo   fclean
	@make -C pwd    fclean
	@make -C cd     fclean
	@make -C env    fclean
	@make -C unset  fclean
	@make -C export fclean
	@make -C exit   fclean
	@make -C ms     fclean
	rm -fr $(BIN_DIR)

re: fclean all

bonus: all
	make -C ls_tester

.PHONY: all echo pwd cd env unset exit ms