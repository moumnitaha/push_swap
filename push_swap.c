/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/03 18:11:12 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**splited;
	char			**tmp;
	int				i;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_printf("Error!\nUsage: ./push_swap <Array>\n");
		return (1);
	}
	while (i < ac)
	{
		splited = ft_split(av[i], ' ');
		tmp = splited;
		while (*splited)
		{
			if (ft_error_syntax(*splited))
				exit(1);
			ft_stack_init(&a, *splited);
			free(*splited);
			splited++;
		}
		free(tmp);
		i++;
	}
	set_position(a);
	if (is_sorted(a))
	{
		printf("[[Sorted Array]]\n");
		exit(0);
	}
	draw_stack(a);
	if (stack_len(a) == 2)
		sa(&a);
	if (stack_len(a) == 3)
		sort_of_three(&a);
	if (stack_len(a) == 5)
		sort_of_five(&a, &b);
	draw_stack(a);
	return (0);
}
