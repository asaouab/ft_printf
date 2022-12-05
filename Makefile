# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:50:50 by asaouab           #+#    #+#              #
#    Updated: 2022/12/03 12:03:01 by asaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c  ft_helper.c

OBJ = $(SRC:.c=.o)

CC = CC

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ) $(HEADER)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME)

re : fclean clean
