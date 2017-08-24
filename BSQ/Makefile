.PHONY: all clean re clean proper

CC := gcc
CFLAGS := -Wall -Werror -Wextra
NAME := bsq
SRC := ft_atoi.c ft_bsq.c ft_error.c ft_file.c ft_putchar.c ft_putnbr.c ft_putstr.c\
	ft_strcat.c ft_strcmp.c ft_strdup.c ft_strlen.c main.c
OBJ := ft_atoi.o ft_bsq.o ft_error.o ft_file.o ft_putchar.o ft_putnbr.o ft_putstr.o\
	ft_strcat.o ft_strcmp.o ft_strdup.o ft_strlen.o main.o
HEADERS = -I includes/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(HEADERS)

%.o : srcs/%.c
	$(CC) $(CFLAGS) -c $< $(HEADERS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

debug:
	@gcc -g srcs/*.c $(HEADERS)