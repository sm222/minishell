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
else
    BIN_DIR = /home/$(USER)/Mini_bin/
endif

all: dirmake echo pwd cd env expo unset exit ms
	

dirmake:
	mkdir -p $(BIN_DIR)

echo:
	@printf "$(GRN)making echo$(WHT)\n"
	@make -C echo

pwd:
	@printf "$(GRN)making pwd$(WHT)\n"
	@make -C pwd

cd:
	@printf "$(GRN)making cd$(WHT)\n"
	@make -C cd

expo:
	@printf "$(GRN)making export$(WHT)\n"
	@make -C export

env:
	@printf "$(GRN)making env$(WHT)\n"
	@make -C env

unset:
	@printf "$(GRN)making unset$(WHT)\n"
	@make -C unset

exit:
	@printf "$(GRN)making exit$(WHT)\n"
	@make -C exit

ms:
	@printf "$(GRN)making ms$(WHT)\n"
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