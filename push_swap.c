/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 12:32:13 by tmoumni          ###   ########.fr       */
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
	{
		ft_printf("Error!\nUsage: ./push_swap <Array>\n");
		exit (1);
	}
	split_args(ac, av, &a);
	if (is_sorted(a))
		exit(0);
	else
	{
		if (stack_len(a) == 2)
			sa(&a);
		if (stack_len(a) == 3)
			sort_of_three(&a);
		if (stack_len(a) > 3)
			main_sort(&a, &b);
	}
	return (0);
}
