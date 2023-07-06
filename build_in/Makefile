
all: echo pwd cd exit
	
echo:
	@make -C echo
pwd:
	@make -C pwd
cd:
	@make -C cd
exit:
	@make -C exit

clean:
	@make -C echo clean
	@make -C pwd  clean
	@make -C cd   clean
	@make -C exit clean

fclean: clean
	@make -C echo fclean
	@make -C pwd  fclean
	@make -C cd   fclean
	@make -C exit fclean

re: fclean all

.PHONY: all echo pwd cd exit