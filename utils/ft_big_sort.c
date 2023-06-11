/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:30:48 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/11 10:33:16 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_b(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	i;
	int	chunk;

	len = stack_len(*a);
	i = 1;
	chunk = (0.000000053 * len * len) + (0.03 * len) + 14.5;
	while (stack_len(*a))
	{
		if ((*a)->index < i)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if ((*a)->index < i + chunk)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
		if (stack_len(*b) > 1 && ((*b)->index < (*b)->next->index))
			sb(b);
	}
}

void	big_sort(t_stack_node **a, t_stack_node **b)
{
	fill_b(a, b);
	while (stack_len(*b))
	{
		set_position(*b);
		rotate_stack_b(b, big_node(*b));
		pa(a, b);
	}
}
