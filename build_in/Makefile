
all: echo pwd cd
	
echo:
	@make -C echo
pwd:
	@make -C pwd
cd:
	@make -C cd

clean:
	@make -C echo clean
	@make -C pwd  clean
	@make -C cd  clean

fclean: clean
	@make -C echo fclean
	@make -C pwd  fclean
	@make -C cd   fclean

re: fclean all

.PHONY: all echo pwd cd