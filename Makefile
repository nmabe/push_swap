# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmabe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 15:47:58 by nmabe             #+#    #+#              #
#    Updated: 2018/09/17 11:01:14 by nmabe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	checker

NAME1 = push_swap

SRC = 		src/ps_controls.c\
			src/ps_get_args.c \
			src/ps_list.c\
			src/ps_checker.c \
			src/ps_print.c \

PS_SRC = 	p_s/src/push_swap.c \
			p_s/src/ps_misc.c	 \
			p_s/src/ps_sort_op.c \
			p_s/src/ps_handler.c \

CHK_SRC =   chkr/src/checker.c \
			chkr/src/chk_checker.c \


CHK_FLAGS = -o $(NAME) -Werror -Wextra -Wall

PS_FLAGS = -o $(NAME1) -Werror -Wextra -Wall

LFLAGS = -L./libft -lft

HEADER = -L includes

all: 
	@make -C libft/ fclean && make -C libft/
	@gcc $(CHK_FLAGS) $(SRC)  $(CHK_SRC) $(HEADER) $(LFLAGS); 
	@gcc $(PS_FLAGS) $(PS_SRC) $(SRC) $(HEADER) $(LFLAGS); #clear
	@echo "\033[22;32m Makefile: '$(NAME1)' & '$(NAME)' Yizinto...\n \033[22;0m"	

clean: 
	@make -C libft/ clean

fclean:
	@rm -rf $(NAME) $(NAME1)
	@rm -rf libft/libft.a
	@echo "\033[22;31m Makefile: '$(NAME)' & $(NAME1) Dololo...\n \033[22;0m"

re: fclean all
