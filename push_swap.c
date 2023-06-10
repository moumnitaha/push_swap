/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 23:24:33 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit (1);
	split_args(ac, av, &a);
	init_nodes(&a, &b);
	index_stack(&a);
	if (is_sorted(a))
		exit(0);
	else
	{
		if (stack_len(a) == 2)
			sa(&a);
		if (stack_len(a) == 3)
			sort_of_three(&a);
		if (stack_len(a) > 3)
			big_sort(&a, &b);
	}
	return (0);
}
