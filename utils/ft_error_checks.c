/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tahadev <tahadev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:31:32 by tmoumni           #+#    #+#             */
/*   Updated: 2025/02/04 19:30:13 by tahadev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	int_max_check(long long nbr)
{
	if (nbr != (int)nbr)
		return (0);
	return (1);
}

int	ft_error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!i && (str[0] == '-' || str[0] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack_node *head)
{
	if (!head)
		return (0);
	if (stack_len(head) == 1)
	{
		free_stack(&head);
		exit(0);
	}
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_b_sorted(t_stack_node *head)
{
	if (!head)
		return (0);
	if (stack_len(head) == 1)
	{
		free_stack(&head);
		exit(0);
	}
	while (head->next)
	{
		if (head->value < head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_error_repitition(t_stack_node **a, int nbr)
{
	t_stack_node	*curr_a;

	curr_a = *a;
	while (curr_a)
	{
		if (curr_a->value == nbr)
			return (1);
		curr_a = curr_a->next;
	}
	return (0);
}
