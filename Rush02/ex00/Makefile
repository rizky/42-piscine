NAME = rush-2
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
	cat tests/rush-00_3_1.txt | ./rush-2;

test: fclean all
	@cat tests/rush-00_3_1.txt;
	@cat tests/rush-00_3_1.txt | ./rush-2;
	@cat tests/rush-00_3_3.txt;
	@cat tests/rush-00_3_3.txt | ./rush-2;
	@cat tests/rush-01_5_3.txt;
	@cat tests/rush-01_5_3.txt | ./rush-2;