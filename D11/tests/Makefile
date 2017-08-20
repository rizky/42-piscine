NAME = main
SRC = $(shell find ../ -name '*.c')

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	clear

debug:
	@gcc -g $(NAME) $(SRC)
