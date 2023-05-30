/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:05:30 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/30 14:49:10 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = ft_find_last_node(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	last_node->prev = NULL;
	(*head)->prev = last_node;
	*head = last_node;
}

void	rra(t_stack_node **a)
{
	ft_rev_rotate(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack_node **b)
{
	ft_rev_rotate(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_putstr("rrr\n");
}
