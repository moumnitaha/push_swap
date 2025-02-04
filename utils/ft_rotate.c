/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:24:48 by tmoumni           #+#    #+#             */
/*   Updated: 2025/02/04 20:04:57 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = ft_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	if (!(*a))
		return ;
	ft_rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack_node **b)
{
	if (!(*b))
		return ;
	ft_rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr("rr\n");
}
