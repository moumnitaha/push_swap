/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:31:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 09:50:48 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	int_max_check(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
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
	while (head->next)
	{
		if (head->value > head->next->value)
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
