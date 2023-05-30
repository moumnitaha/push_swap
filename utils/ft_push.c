/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:39:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/30 12:24:49 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	t_stack_node	*last_node;

	if (!(*src))
		return ;
	node_to_push = ft_find_last_node(*src);
	if (!(*dest))
	{
		node_to_push->prev->next = NULL;
		*dest = node_to_push;
		node_to_push->next = NULL;
		node_to_push->prev = NULL;
	}
	else
	{
		node_to_push->prev->next = NULL;
		last_node = ft_find_last_node(*dest);
		last_node->next = node_to_push;
		last_node->next->prev = last_node;
		last_node->next->next = NULL;
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
