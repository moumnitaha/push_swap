/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:24:48 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/29 18:40:56 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = ft_find_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra(a);
	rb(b);
	ft_putstr("rr\n");
}
