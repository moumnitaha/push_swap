/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/05/30 14:54:54 by tmoumni          ###   ########.fr       */
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
		return (1);
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
	draw_stack(a);
	ft_putstr("---\n");
	sa(&a);
	draw_stack(a);
	// ft_putstr("---\n");
	// draw_stack(b);
	// rrr(&a, &b);
	// draw_stack(a);
	// ft_putstr("---\n");
	// draw_stack(b);
	return (0);
}
