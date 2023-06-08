/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:33:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 16:19:06 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_init(t_stack_node **a, char *arg)
{
	long			nbr;

	nbr = ft_atoll(arg);
	if (!int_max_check(nbr))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (ft_error_repitition(a, nbr))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_append_node(a, nbr);
}
