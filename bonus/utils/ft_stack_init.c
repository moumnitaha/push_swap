/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:33:33 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 14:49:11 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_stack_init(t_stack_node **a, char *arg)
{
	long			nbr;

	nbr = ft_atoll(arg);
	if (!int_max_check(nbr))
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (ft_error_repitition(a, nbr))
	{
		ft_printf("Error\n");
		exit (1);
	}
	ft_append_node(a, nbr);
}