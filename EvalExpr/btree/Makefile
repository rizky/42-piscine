NAME = evalexpr
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	clear;
	gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR)

debug:
	clear;
	gcc -g $(SRC) -I$(HEADER_DIR)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: fclean all
		./evalexpr "(0 - 1) + (0 - 5)"