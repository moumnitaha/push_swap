/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:22:37 by tmoumni           #+#    #+#             */
/*   Updated: 2025/02/04 20:16:14 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h> 
# include "../ft_printf/ft_printf.h"
# include "utils_bonus/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					above_median;
	struct s_stack_node	*target_node_up;
	struct s_stack_node	*target_node_down;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

t_stack_node	*small_node(t_stack_node *head);
t_stack_node	*big_node(t_stack_node *head);
t_stack_node	*ft_last_node(t_stack_node *head);
int				ft_error_syntax(char *str);
int				ft_error_repitition(t_stack_node **a, int nbr);
int				int_max_check(long long nbr);
int				is_sorted(t_stack_node *head);
int				stack_len(t_stack_node *head);
int				is_sorted(t_stack_node *head);
char			*get_next_line(int fd);
void			*free_mem(char **array);
void			exit_error(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **stack);
void			draw_stack(t_stack_node *head);
void			split_args(int ac, char **av, t_stack_node **a);
void			init_nodes(t_stack_node **a, t_stack_node **b);
void			rotate_stack_a(t_stack_node **a, t_stack_node *node);
void			rotate_stack_b(t_stack_node **b, t_stack_node *node);
void			ft_append_node(t_stack_node **stack, int nbr);
void			ft_stack_init(t_stack_node **a, char *arg, char **tmp);
void			sort_of_three(t_stack_node **head);
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
void			ft_rev_rotate(t_stack_node **head);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
long long		ft_atoll(const char *str);
#endif
