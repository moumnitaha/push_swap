/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:21:21 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 09:26:05 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack_a(t_stack_node **a, t_stack_node *node)
{
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

int	has_targt_up(t_stack_node **stack)
{
	int				target;
	t_stack_node	*head;

	target = 0;
	head = *stack;
	while (head)
	{
		if (head->target_node_up)
			target++;
		head = head->next;
	}
	return (target);
}

int	has_targt_down(t_stack_node **stack)
{
	int				target;
	t_stack_node	*head;

	head = *stack;
	target = 0;
	while (head)
	{
		if (head->target_node_down)
			target++;
		head = head->next;
	}
	return (target);
}

void	main_sort(t_stack_node **a, t_stack_node **b)
{
	init_nodes(a, b);
	get_target_node_up(a, b);
	while (has_targt_up(a))
	{
		rotate_stack_a(a, target_up_node(a));
		rotate_stack_b(b, target_up_node(a)->target_node_up);
		pa(a, b);
		init_nodes(a, b);
		get_target_node_up(a, b);
	}
	rotate_stack_a(a, small_node(*a));
	init_nodes(a, b);
	get_target_node_down(a, b);
	while (has_targt_down(a))
	{
		rotate_stack_b(b, target_down_node(a)->target_node_down);
		target_down_node(a)->target_node_down = NULL;
		pa(a, b);
		ra(a);
		init_nodes(a, b);
		get_target_node_down(a, b);
	}
}
