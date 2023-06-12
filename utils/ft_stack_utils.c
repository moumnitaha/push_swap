/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/12 11:30:45 by tmoumni          ###   ########.fr       */
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

void	sort_of_five(t_stack_node **a, t_stack_node **b)
{
	set_position(*a);
	rotate_stack_a(a, small_node(*a));
	if (is_sorted(*a))
		return ;
	pb(b, a);
	set_position(*a);
	rotate_stack_a(a, small_node(*a));
	pb(b, a);
	sort_of_three(a);
	while (*b)
		pa(a, b);
}
