/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:31:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/11 17:24:51 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	split_args(int ac, char **av, t_stack_node **a)
{
	char			**splited;
	char			**tmp;
	int				i;

	i = 1;
	while (i < ac)
	{
		splited = ft_split(av[i], ' ');
		tmp = splited;
		while (*splited)
		{
			if (ft_error_syntax(*splited))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			ft_stack_init(a, *splited);
			free(*splited);
			splited++;
		}
		free(tmp);
		i++;
	}
}
