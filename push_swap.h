/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:42:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/29 17:45:42 by tmoumni          ###   ########.fr       */
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

typedef struct s_stack_node {
	int					value;
	int					current_pos;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*ft_find_last_node(t_stack_node *head);
void			ft_append_node(t_stack_node **stack, int nbr);
void			ft_stack_init(t_stack_node **a, char **av);
int				ft_error_syntax(char *str);
int				ft_error_repitition(char **av, int nbr);
long			ft_atol(const char *str);
void			ft_push(t_stack_node **src, t_stack_node **dest);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ft_swap(t_stack_node **stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ft_rotate(t_stack_node **head);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
#endif
