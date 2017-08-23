NAME = eval-expr
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR)

debug:
	gcc -g $(SRC) -I$(HEADER_DIR)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: fclean all
	./evalexpr "1 - 5 - 1";

test: fclean all
	./evalexpr "1 + 2 + ( ( ( 3  *  4 + 4 * 3 / 2 * 2 * 2) + 3 + 22 ) + 6 * ( ( 2 *  (-9) ) + 2 )  ) -1 - 5";
	./evalexpr "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1";