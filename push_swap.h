/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:42:00 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/05 14:23:31 by tmoumni          ###   ########.fr       */
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
	int					above_median;
	int					isTarget;
	int					push_price;
	int					cheapest;
	struct s_stack_node	*target_node_up;
	struct s_stack_node	*target_node_down;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*ft_find_last_node(t_stack_node *head);
t_stack_node	*big_node(t_stack_node *head);
t_stack_node	*small_node(t_stack_node *head);
void	set_target_node(t_stack_node *a, t_stack_node *b);
void	set_price(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *b);
void	get_target_node_up(t_stack_node **a, t_stack_node **b);
void	set_push_price(t_stack_node **stack);
t_stack_node	*sheap_node(t_stack_node **a);
void	init_nodes(t_stack_node **a, t_stack_node **b);
void	rotate_stack_a(t_stack_node **a, t_stack_node *node);
void	rotate_stack_b(t_stack_node **b, t_stack_node *node);
int		has_targt(t_stack_node **stack);
void	fix_head(t_stack_node **stack, t_stack_node *head);
void main_sort(t_stack_node **a, t_stack_node **b);
void			ft_append_node(t_stack_node **stack, int nbr);
void			ft_stack_init(t_stack_node **a, char *arg);
void			sort_of_five(t_stack_node **a, t_stack_node **b);
void			sort_of_four(t_stack_node **a, t_stack_node **b);
void			sort_of_three(t_stack_node **head);
int				ft_error_syntax(char *str);
int				ft_error_repitition(char **av, int nbr);
int				int_check(long nbr);
int				is_sorted(t_stack_node *head);
int				stack_len(t_stack_node *head);
long			ft_atol(const char *str);
void			set_position(t_stack_node *head);
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
void			draw_stack(t_stack_node *head);
void			ft_rev_rotate(t_stack_node **head);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
#endif
