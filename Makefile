# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 17:39:10 by tmoumni           #+#    #+#              #
#    Updated: 2023/06/08 16:18:46 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

BOLD = \033[1m
GREEN = \033[1;32m
RED=\033[1;31m
CYAN = \033[1;36m
END = \033[0m

SRCS = ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c\
	ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c push_swap.c\
	utils/ft_split.c utils/ft_isalnum.c utils/ft_isdigit.c utils/ft_isalpha.c\
	utils/ft_stack_init.c utils/ft_stack_utils.c utils/ft_atoll.c utils/ft_push.c utils/ft_swap.c\
	utils/ft_rotate.c utils/ft_rev_rotate.c utils/ft_taget_nodes.c utils/ft_node_utils.c\
	utils/ft_main_sort.c utils/ft_error_checks.c utils/ft_split_args.c utils/ft_draw_stack.c
OBJS = $(SRCS:%.c=%.o)

B_SRCS = bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c bonus/bonus_checker.c\
		ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/ft_putchar.c ft_printf/ft_putstr.c\
		ft_printf/ft_puthex.c ft_printf/ft_putunbr.c ft_printf/ft_putptr.c\
		bonus/utils/ft_split.c bonus/utils/ft_split_args.c bonus/utils/ft_error_checks.c bonus/utils/ft_atoll.c bonus/utils/ft_rev_rotate.c bonus/utils/ft_rotate.c bonus/utils/ft_node_utils.c\
		bonus/utils/ft_isalnum.c bonus/utils/ft_isdigit.c bonus/utils/ft_isalpha.c bonus/utils/ft_stack_init.c bonus/utils/ft_draw_stack.c bonus/utils/ft_push.c bonus/utils/ft_swap.c bonus/utils/ft_strncmp.c 
B_OBJS = $(B_SRCS:%.c=%.o)

all: $(NAME)
	@echo "\n$(GREEN)[[ push_swap created successfully ]]$(END)\n"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

$(NAME): $(SRCS) $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME) $(B_OBJS) $(B_SRCS)
	@$(CC) $(CFLAGS) $(B_OBJS) -o $(CHECKER)
	@echo "\n$(GREEN)[[ checker created successfully ]]$(END)\n"

clean:
	@rm -rf $(OBJS) $(B_OBJS)

fclean:
	@rm -rf $(OBJS) $(B_OBJS) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re