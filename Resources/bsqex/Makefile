#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scornaz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 18:52:35 by scornaz           #+#    #+#              #
#    Updated: 2017/08/21 21:38:30 by scornaz          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq
INCLUDES = includes
C_DIR = srcs/
C_FILES = main.c algo.c ft_read_map.c ft_print.c
SRCS = $(addprefix $(C_DIR), $(C_FILES))
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CMD = cc -c $(FLAGS) -I$(INCLUDES) $(SRCS)
CMD_DEBUG = cc -c -g $(FLAGS) -I$(INCLUDES) $(SRCS)

all: $(NAME)

$(NAME):
	$(CMD)
	mv *o objs	
	cc -o $(NAME) objs/*o

debug:
	$(CMD_DEBUG)
	mv *o objs	
	cc -o $(NAME) objs/*o

clean:
	/bin/rm -f objs/*

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all