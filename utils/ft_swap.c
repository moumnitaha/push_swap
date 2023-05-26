/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/26 18:51:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !(*head) || !(*head)->next)
		return ;
	tmp = (*head)->next;
	tmp->next = *head;
	(*head)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *head;
	*head = tmp;
	(*head)->prev = NULL;
}

void	sa(t_stack **a)
{
	ft_swab(a);
	ft_putstr("sa\n");
}

void	sb(t_stack **b)
{
	ft_swab(b);
	ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swab(a);
	ft_swab(b);
	ft_putstr("ss\n");
}
