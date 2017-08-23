NAME = bsq
SRC = srcs/*.c
HEADER_DIR = includes

all: $(NAME)

$(NAME):
	@#gcc -o $(NAME) -Wall -Werror -Wextra $(SRC) -I$(HEADER_DIR);
	@gcc -o $(NAME) $(SRC) -I$(HEADER_DIR);

debug:
	@gcc -g $(SRC) -I$(HEADER_DIR);

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

run: fclean all
	./bsq files/a.txt;

stdin: fclean all
	perl bsq.pl 15 15 5 | ./bsq

extreme: fclean all
	time ./bsq files/extreme.txt > outputs/output.txt

test: fclean all
	./bsq files/a.txt;
	perl bsq.pl 6 18 3 | ./bsq
	./bsq files/a.txt files/b.txt;
	time ./bsq files/extreme.txt > outputs/output.txt
	time perl bsq.pl 2000 2000 300 | ./bsq > outputs/output.txt