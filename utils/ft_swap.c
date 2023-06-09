/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 11:18:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack_node **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	if ((*head)->next)
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
	}
	else
		(*head)->prev->next = NULL;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	if (!(*a))
		return ;
	ft_swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack_node **b)
{
	if (!(*b))
		return ;
	ft_swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_putstr("ss\n");
}
