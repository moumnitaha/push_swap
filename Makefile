# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 17:39:10 by tmoumni           #+#    #+#              #
#    Updated: 2023/05/29 17:38:17 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
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
	libft/ft_split.c libft/ft_atoi.c libft/ft_isalnum.c libft/ft_isdigit.c libft/ft_isalpha.c\
	utils/ft_stack_init.c utils/ft_stack_utils.c utils/ft_atol.c utils/ft_push.c utils/ft_swap.c\
	utils/ft_rotate.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)
	@echo "\n$(GREEN)[[ push_swap created successfully ]]$(END)\n"

%.o : %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

$(NAME): $(SRCS) $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean:
	@rm -rf $(OBJS) $(NAME)

re: fclean all