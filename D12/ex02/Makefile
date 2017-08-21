NAME = ft_tail
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

run: fclean all
		./ft_tail -c 50 srcs/ft_putchar.c;
		tail -c 50 srcs/ft_putchar.c;
	
diff: fclean all
		./ft_tail -c 50 srcs/ft_putchar.c files/a.txt files/c.txt > outputs/a.txt;
		tail -c 50 srcs/ft_putchar.c files/a.txt files/c.txt > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

test: fclean all
		./ft_tail -c 50 srcs/ft_putchar.c;
		tail -c 50 srcs/ft_putchar.c;
		./ft_tail -c 50 files/a.txt;
		tail -c 50 files/a.txt;
		./ft_tail -c 50 srcs/ft_putchar.c files/a.txt files/b.txt;
		tail -c 50 srcs/ft_putchar.c files/a.txt files/b.txt;