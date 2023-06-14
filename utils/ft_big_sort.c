/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:30:48 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/14 13:39:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_chunk(int len)
{
	if (len <= 100)
		return (15);
	else if (len <= 500)
		return (30);
	else if (len <= 1000)
		return (45);
	else if (len <= 2000)
		return (65);
	else
		return (150);
}

void	fill_b(t_stack_node **a, t_stack_node **b)
{
	int	len;
	int	i;
	int	chunk;

	len = stack_len(*a);
	i = 1;
	chunk = set_chunk(len);
	while (stack_len(*a))
	{
		if ((*a)->index < chunk + i)
		{
			pb(b, a);
			if ((*b)->index < i)
				rb(b);
			i++;
		}
		else
			ra(a);
		if (stack_len(*b) > 1 && ((*b)->value < (*b)->next->value))
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

void	sort_of_four(t_stack_node **a, t_stack_node **b)
{
	rotate_stack_a(a, small_node(*a));
	if (is_sorted(*a))
		return ;
	pb(b, a);
	sort_of_three(a);
	pa(a, b);
}
