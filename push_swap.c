/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/12 17:36:16 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorting(t_stack_node **a, t_stack_node **b)
{
	if (is_sorted(*a))
	{
		free_stacks(a, b);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac > 1 && !av[1][0]))
		exit (0);
	split_args(ac, av, &a);
	init_nodes(&a, &b);
	index_stack(&a);
	check_sorting(&a, &b);
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_of_three(&a);
	else if (stack_len(a) == 4)
		sort_of_four(&a, &b);
	else if (stack_len(a) == 5)
		sort_of_five(&a, &b);
	else
		big_sort(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
