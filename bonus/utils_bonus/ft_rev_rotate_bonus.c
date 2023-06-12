/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:05:30 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:33:55 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ft_rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = ft_last_node(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	last_node->prev = NULL;
	(*head)->prev = last_node;
	*head = last_node;
}

void	rra(t_stack_node **a)
{
	if (!(*a))
		return ;
	ft_rev_rotate(a);
}

void	rrb(t_stack_node **b)
{
	if (!(*b))
		return ;
	ft_rev_rotate(b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}
