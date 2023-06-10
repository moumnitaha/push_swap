/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:21:21 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:18:48 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack_a(t_stack_node **a, t_stack_node *node)
{
	if (!stack_len(*a))
		return ;
	if (node->above_median)
	{
		while ((*a)->value != node->value)
			ra(a);
	}
	else
	{
		while ((*a)->value != node->value)
			rra(a);
	}
}

void	rotate_stack_b(t_stack_node **b, t_stack_node *node)
{
	if (!stack_len(*b))
		return ;
	if (node->above_median)
	{
		while ((*b)->value != node->value)
			rb(b);
	}
	else
	{
		while ((*b)->value != node->value)
			rrb(b);
	}
}
