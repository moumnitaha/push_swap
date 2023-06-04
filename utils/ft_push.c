/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:39:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/04 11:22:07 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	t_stack_node	*top_node;

	if (!(*src))
		return ;
	node_to_push = *src;
	if (!(*dest))
	{
		if (node_to_push->next)
		{
			node_to_push->next->prev = NULL;
			*src = node_to_push->next;
		}
		else
			*src = NULL;
		*dest = node_to_push;
		node_to_push->next = NULL;
		node_to_push->prev = NULL;
	}
	else
	{
		if (node_to_push->next)
		{
			node_to_push->next->prev = NULL;
			*src = node_to_push->next;
		}
		else
			*src = NULL;
		top_node = *dest;
		top_node->prev = node_to_push;
		node_to_push->next = top_node;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	ft_push(b, a);
	ft_putstr("pb\n");
}
