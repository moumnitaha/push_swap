/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:33:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/11 17:25:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	ft_stack_init(t_stack_node **a, char *arg)
{
	long			nbr;

	nbr = ft_atoll(arg);
	if (!int_max_check(nbr))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (ft_error_repitition(a, nbr))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	ft_append_node(a, nbr);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
