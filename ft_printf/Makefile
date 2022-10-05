# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2022/09/16 04:16:06 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIR = ./

COM = gcc

RM = rm -f

FLAG = -Wall -Werror -Wextra

FILEMAN = ft_printf.c ft_argument.c

SRCSMAN = $(addprefix $(DIR), $(FILEMAN))

OBJMAN = $(SRCSMAN:.c=.o)

.c.o:
	$(COM) $(FLAG) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJMAN)
	ar rc $(NAME) $(OBJMAN)

clean:
	$(RM) $(OBJMAN)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re