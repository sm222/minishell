
all: echo pwd cd env exit
	
echo:
	@make -C echo
pwd:
	@make -C pwd
cd:
	@make -C cd
env:
	@make -C env
exit:
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