/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taget_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:09:23 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 11:25:45 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pos(int num)
{
	if (num < 0)
		num -= num;
	return (num);
}

void	get_target_node_up(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	long long		diff;

	diff = LLONG_MIN;
	current_a = *a;
	while (current_a)
	{
		current_b = *b;
		current_a->target_node_up = NULL;
		while (current_b)
		{
			if ((current_b)->value < current_a->value)
			{
				if (pos((current_b)->value - current_a->value) > diff)
				{
					diff = pos((current_b)->value - current_a->value);
					current_a->target_node_up = (current_b);
				}
			}
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

void	get_target_node_down(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	long long		diff;

	if (!stack_len(*a))
		return ;
	diff = LLONG_MAX;
	current_a = ft_last_node(*a);
	current_b = *b;
	current_a->target_node_down = NULL;
	while (current_b)
	{
		if ((current_b)->value > current_a->value)
		{
			if (pos((current_b)->value - current_a->value) < diff)
			{
				diff = pos((current_b)->value - current_a->value);
				current_a->target_node_down = (current_b);
			}
		}
		current_b = current_b->next;
	}
}

t_stack_node	*target_up_node(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*node;

	node = NULL;
	head = *stack;
	while (head)
	{
		if (head->target_node_up)
		{
			node = head;
			break ;
		}
		head = head->next;
	}
	return (node);
}

t_stack_node	*target_down_node(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*node;

	node = NULL;
	head = *stack;
	while (head)
	{
		if (head->target_node_down)
		{
			node = head;
			break ;
		}
		head = head->next;
	}
	return (node);
}
