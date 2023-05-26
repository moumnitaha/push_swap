/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/26 18:37:32 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
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
