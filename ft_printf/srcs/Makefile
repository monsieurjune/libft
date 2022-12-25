# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 03:48:25 by tponutha          #+#    #+#              #
#    Updated: 2022/12/25 05:37:06 by tponutha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main properties
NAME		= libftprintf.a
TESTER_PATH	= ../

# Complier & shell thing
COM		= gcc
RM		= rm -f
CFLAG	= -Wall -Werror -Wextra

# Main Directory
MAIN_DIR	= ./
MAIN_FILE	= ft_printf.c
MAIN_SRCS	= $(addprefix $(MAIN_DIR), $(MAIN_FILE))

# Error Handler
ERR_DIR		= error/
ERR_FILE	= 
ERR_SRCS	= $(addprefix $(ERR_DIR), $(ERR_FILE))

# Flag Handler
FLAG_DIR	= flag/
FLAG_FILE	= 
FLAG_SRCS	= $(addprefix $(FLAG_DIR), $(FLAG_FILE))

# Conversion Handler
CONV_DIR	= conv/
CONV_FILE	= 
CONV_SRCS	= $(addprefix $(CONV_DIR), $(CONV_FILE))

# Complie Process
SRCS	= $(MAIN_SRCS) $(ERR_SRCS) $(FLAG_SRCS) $(CONV_SRCS)
OBJ		= $(SRCS:.c=.o)
IFLAG	= -I$(MAIN_DIR) -I$(ERR_DIR) -I$(FLAG_DIR) -I$(CONV_DIR)
.c.o:
	$(COM) $(CFLAG) -c $(IFLAG) $< -o $(<:.c=.o)

# MAIN RULES
$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all:	$(NAME)

bonus:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

# ETC RULES
test:
	@make -C $(TESTER_PATH)print1/
	@bash $(TESTER_PATH)print2/runtest.sh
	@make -C $(TESTER_PATH)print3/
	@bash $(TESTER_PATH)print4/run.sh

clone:
	@rm -rf $(TESTER_PATH)print1 $(TESTER_PATH)print2 $(TESTER_PATH)print3 $(TESTER_PATH)print4
	@git clone git@github.com:Tripouille/printfTester.git $(TESTER_PATH)print1
	@git clone git@github.com:Mazoise/42TESTERS-PRINTF.git $(TESTER_PATH)print2
	@git clone git@github.com:paulo-santana/ft_printf_tester.git $(TESTER_PATH)print3
	@git clone git@github.com:romslf/ft_printf_tester.git $(TESTER_PATH)print4
	@rm -rf $(TESTER_PATH)print1/.git $(TESTER_PATH)print2/.git $(TESTER_PATH)print3/.git $(TESTER_PATH)print4/.git

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

.PHONY: all clean fclean re bonus test clone