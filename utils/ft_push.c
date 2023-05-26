/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:39:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/26 17:58:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*new;

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

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_putstr("pb\n");
}
