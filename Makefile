# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 22:05:44 by tponutha          #+#    #+#              #
#    Updated: 2022/09/04 11:24:37 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Description
NAME				= libft.a

# Compiler Properties
CC					= cc
CFLAG				= -Wall -Werror -Wextra
RM					= rm -f

# Source
ROOT_SRC_PATH		= ./
LIBFT_HEADER		= ./libft.h
MANDATORY_SRC		= ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_memchr.c \
						ft_memcpy.c \
						ft_memcmp.c \
						ft_memmove.c \
						ft_memset.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_strlcat.c \
						ft_striteri.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_split.c \
						ft_itoa.c \
						ft_strmapi.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c

BONUS_SRC			= ft_lstnew.c \
						ft_lstadd_front.c \
						ft_lstsize.c \
						ft_lstlast.c \
						ft_lstadd_back.c \
						ft_lstdelone.c \
						ft_lstclear.c \
						ft_lstiter.c \
						ft_lstmap.c

MANDATORY_SRCS		= $(addprefix $(ROOT_SRC_PATH), $(MANDATORY_SRC))
BONUS_SRCS			= $(addprefix $(ROOT_SRC_PATH), $(BONUS_SRC))

# Object
MANDATORY_OBJS		= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS			= $(BONUS_SRCS:.c=.o)
LIBFT_OBJS			= $(MANDATORY_OBJS) $(BONUS_OBJS)

# Object Compile Setting
%.o: %.c $(LIBFT_HEADER) Makefile
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

# Main Rules
all:	$(NAME)

$(NAME):	$(LIBFT_OBJS)
	ar rcs $(NAME) $(LIBFT_OBJS)

clean:
	$(RM) $(LIBFT_OBJS)

fclean:	clean
	$(RM) $(NAME)

bonus:	$(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus