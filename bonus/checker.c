/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:44:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 12:52:20 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	char			*line;
	int				fd;
	t_stack_node	*a;

	fd = STDIN_FILENO;
	a = NULL;
	line = get_next_line(fd);
	if (!line)
		exit (1);
	split_args(ac, av, &a);
	while (line)
	{
		printf("<%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
