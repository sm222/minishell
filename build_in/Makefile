
all: echo pwd
	
echo:
	@make -C echo
pwd:
	@make -C pwd

clean:
	@make -C echo clean
	@make -C pwd  clean

fclean: clean
	@make -C echo fclean
	@make -C pwd  fclean

re: fclean all

.PHONY: all echo pwd