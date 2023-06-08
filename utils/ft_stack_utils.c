/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 09:33:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	draw_stack(t_stack_node *head)
// {
// 	ft_printf("-----\n");
// 	while (head)
// 	{
// 		ft_printf("|%d|\t", head->value);
// 		if (head->target_node_up)
// 			ft_printf("trgUp: (%d)\t", head->target_node_up->value);
// 		if (head->target_node_down)
// 			ft_printf("trgDown: (%d)\n", head->target_node_down->value);
// 		else
// 			ft_printf("\n");
// 		head = head->next;
// 	}
// 	ft_printf("-----\n");
// }

void	set_position(t_stack_node *head)
{
	int	mid;
	int	i;

	mid = stack_len(head) / 2;
	i = 0;
	while (head)
	{
		head->current_pos = i;
		if (i > mid)
			head->above_median = 0;
		else
			head->above_median = 1;
		head = head->next;
		i++;
	}
}

void	sort_of_three(t_stack_node **head)
{
	t_stack_node	*big;

	big = big_node(*head);
	if (*head == big)
		ra(head);
	if ((*head)->next == big)
		rra(head);
	if ((*head)->next == small_node(*head))
		sa(head);
}

void	init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_position(*a);
	set_position(*b);
}
