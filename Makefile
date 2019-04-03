NAME = ft_printf

SRC = flag_priority.c ft_printf.c parse_flags.c print_arg.c print_double.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wextra -Wall -Werror

ifndef VERBOSE
.SILENT:
endif

all:$(NAME)

$(NAME): $(OBJ)
	make -C libftprintf
	mv libftprintf/libftprintf.a .

clean:
	/bin/rm -f $(OBJ)
	echo "\033[32mAll .o have been erased.\033[0m"

fclean: clean
	/bin/rm -f $(NAME)
	echo "\033[32m$(NAME) erased.\033[0m"

re: fclean all
