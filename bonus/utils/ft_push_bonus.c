/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:39:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:33:51 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	fix_src(t_stack_node *node_to_push, t_stack_node **src)
{
	if (node_to_push->next)
	{
		node_to_push->next->prev = NULL;
		*src = node_to_push->next;
	}
	else
		*src = NULL;
}

void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	t_stack_node	*top_node;

	if (!(*src))
		return ;
	node_to_push = *src;
	fix_src(node_to_push, src);
	if (!(*dest))
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
		node_to_push->prev = NULL;
	}
	else
	{
		top_node = *dest;
		top_node->prev = node_to_push;
		node_to_push->next = top_node;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (!(*b))
		return ;
	ft_push(a, b);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	if (!(*a))
		return ;
	ft_push(b, a);
}
