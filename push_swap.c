/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/12 12:25:13 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit (0);
	if (ac > 1 && !av[1][0])
		exit_err();
	split_args(ac, av, &a);
	init_nodes(&a, &b);
	index_stack(&a);
	if (is_sorted(a))
		exit(0);
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_of_three(&a);
	else if (stack_len(a) == 5)
		sort_of_five(&a, &b);
	else
		big_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
