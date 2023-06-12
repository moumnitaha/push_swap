/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:31:51 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/12 17:32:59 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	check_splited(char **splited)
{
	if (*splited == NULL)
	{
		free_mem(splited);
		exit(1);
	}
}

void	split_args(int ac, char **av, t_stack_node **a)
{
	char			**splited;
	char			**tmp;
	int				i;

	i = 1;
	while (i < ac)
	{
		splited = ft_split(av[i], ' ');
		check_splited(splited);
		tmp = splited;
		while (*splited)
		{
			if (ft_error_syntax(*splited))
			{
				free_mem(tmp);
				free_stack(a);
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_stack_init(a, *splited, tmp);
			splited++;
		}
		free_mem(tmp);
		i++;
	}
}
