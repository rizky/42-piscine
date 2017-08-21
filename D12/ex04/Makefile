NAME = ft_last
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
		./ft_hexdump -C files/a.txt files/b.txt;
		hexdump -C files/a.txt files/b.txt;
	
diff: fclean all
		./ft_hexdump files/a.txt  > outputs/a.txt;
		hexdump files/a.txt  > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

		./ft_hexdump files/a.txt files/b.txt | cat -e  > outputs/a.txt;
		hexdump files/a.txt files/b.txt | cat -e > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

		./ft_hexdump files/b.txt | cat -e  > outputs/a.txt;
		hexdump files/b.txt | cat -e  > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

		./ft_hexdump -C files/b.txt | cat -e  > outputs/a.txt;
		hexdump -C files/b.txt | cat -e  > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

		./ft_hexdump -C files/a.txt files/b.txt | cat -e  > outputs/a.txt;
		hexdump -C files/a.txt files/b.txt | cat -e  > outputs/b.txt;
		diff -u outputs/a.txt outputs/b.txt;

test: fclean all
		./ft_hexdump files/a.txt;
		hexdump files/a.txt;
		./ft_hexdump files/b.txt;
		hexdump files/b.txt;	
		./ft_hexdump files/a.txt files/b.txt;
		hexdump files/a.txt files/b.txt;
		./ft_hexdump files/b.txt;
		hexdump files/b.txt;
		./ft_hexdump -C files/b.txt;
		hexdump -C files/b.txt;
		./ft_hexdump -C files/a.txt files/b.txt;
		hexdump -C files/a.txt files/b.txt;