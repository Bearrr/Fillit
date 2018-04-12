#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 13:27:54 by vdoroshy          #+#    #+#              #
#    Updated: 2016/12/26 15:47:41 by vdoroshy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = algorithm.o \
			ft_functions.o \
			isvalid.o \
			list_cut1.o \
			list_cut2.o \
			main.o \

.PHONY : clean all fclean re

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

algorithm.o : algorithm.c
	$(CC) $(CFLAGS) -c algorithm.c

ft_functions.o : ft_functions.c
	$(CC) $(CFLAGS) -c ft_functions.c

isvalid.o : isvalid.c
	$(CC) $(CFLAGS) -c isvalid.c

list_cut1.o : list_cut1.c
	$(CC) $(CFLAGS) -c list_cut1.c

list_cut2.o : list_cut2.c
	$(CC) $(CFLAGS) -c list_cut2.c

main.o : main.c
	$(CC) $(CFLAGS) -c main.c