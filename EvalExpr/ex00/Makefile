NAME = evalexpr
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	# gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR)
	clear;
	gcc -o $(NAME) $(SRC) -I$(HEADER_DIR)

debug:
	clear;
	gcc -g $(SRC) -I$(HEADER_DIR)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: fclean all
		./evalexpr "1 + 1 * 5 + 1"