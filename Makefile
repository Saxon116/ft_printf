NAME = libftprintf.a

ifndef VERBOSE
.SILENT:
endif

all:$(NAME)

$(NAME): libftprintf/libftprintf.a
	make -C libftprintf
	mv libftprintf/libftprintf.a .

clean:
	make -C libftprintf clean
	echo "\033[32mAll .o have been erased.\033[0m"

fclean: clean
	make -C libftprintf fclean
	echo "\033[32m$(NAME) erased.\033[0m"

re: fclean all
