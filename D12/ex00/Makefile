NAME = ft_display_file
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all