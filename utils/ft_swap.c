/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/30 16:43:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr("ss\n");
}
