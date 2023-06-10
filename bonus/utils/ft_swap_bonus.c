/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:34:20 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
}

void	sb(t_stack_node **b)
{
	if (!(*b))
		return ;
	ft_swap(b);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (!(*a) || !(*b))
		return ;
	ft_swap(a);
	ft_swap(b);
}
