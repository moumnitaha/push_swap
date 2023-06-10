/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:16:02 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_position(t_stack_node *head)
{
	int	mid;
	int	i;

	mid = stack_len(head) / 2;
	i = 0;
	while (head)
	{
		head->current_pos = i;
		head->index = 0;
		if (i > mid)
			head->above_median = 0;
		else
			head->above_median = 1;
		head = head->next;
		i++;
	}
}

void	sort_of_three(t_stack_node **head)
{
	t_stack_node	*big;

	if (!(*head))
		return ;
	big = big_node(*head);
	if (*head == big)
		ra(head);
	if ((*head)->next == big)
		rra(head);
	if ((*head)->next == small_node(*head))
		sa(head);
}

void	init_nodes(t_stack_node **a, t_stack_node **b)
{
	set_position(*a);
	set_position(*b);
}

void	index_stack(t_stack_node **a)
{
	t_stack_node	*i;
	t_stack_node	*j;
	t_stack_node	*head;

	head = *a;
	i = head->next;
	while (i)
	{
		j = head;
		while (j->current_pos < i->current_pos)
		{
			if (i->value > j->value)
				i->index++;
			else
				j->index++;
			j = j->next;
		}
		i = i->next;
	}
}

void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int i = 1;
	int j = 15;
	if (stack_len(*a) > 250)
		j = 25;
	while (stack_len(*a))
	{
		if ((*a)->index < i)
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else if ((*a)->index < i + j)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
		if (stack_len(*b) > 1)
		{
			if ((*b)->index < (*b)->next->index)
				sb(b);
		}
		// draw_stack(*b);
	}
	while (stack_len(*b))
	{
		set_position(*b);
		rotate_stack_b(b, big_node(*b));
		pa(a, b);
	}
}