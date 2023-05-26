/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:42:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/26 18:29:08 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h> 
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack {
	int				value;
	int				current_pos;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_find_last_node(t_stack *head);
void	ft_append_node(t_stack **stack, int nbr);
void	ft_stack_init(t_stack **a, char **av);
int		ft_error_syntax(char *str);
int		ft_error_repitition(char **av, int nbr);
long	ft_atol(const char *str);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ft_swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
#endif
