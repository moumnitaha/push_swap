/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:31:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 09:32:40 by tmoumni          ###   ########.fr       */
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

int	ft_error_repitition(char **av, int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nbr)
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}
