/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:39:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/29 17:42:53 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*new;

	if (!(*src))
		return ;
	new = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!(*dest))
	{
		*dest = new;
		new->next = NULL;
	}
	else
	{
		new->next = *dest;
		(*dest)->prev = new;
		*dest = new;
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
