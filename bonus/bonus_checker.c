/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:44:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 13:21:54 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	char			*line;
	int				len;
	int				fd;
	t_stack_node	*a;
	t_stack_node	*b;

	fd = STDIN_FILENO;
	a = NULL;
	b = NULL;
	line = get_next_line(fd);
	if (!line)
		exit (1);
	split_args(ac, av, &a);
	len = stack_len(a);
	while (line)
	{
		if (!strcmp(line, "sa\n"))
			sa(&a);
		if (!strcmp(line, "sb\n"))
			sb(&b);
		if (!strcmp(line, "ss\n"))
			ss(&a, &b);
		if (!strcmp(line, "pa\n"))
			pa(&a, &b);
		if (!strcmp(line, "pb\n"))
			pb(&b, &a);
		if (!strcmp(line, "ra\n"))
			ra(&a);
		if (!strcmp(line, "rb\n"))
			rb(&b);
		if (!strcmp(line, "rr\n"))
			rr(&a, &b);
		if (!strcmp(line, "rra\n"))
			rra(&a);
		if (!strcmp(line, "rrb\n"))
			rrb(&b);
		if (!strcmp(line, "rrr\n"))
			rrr(&a, &b);
		line = get_next_line(fd);
	}
	if (is_sorted(a) && len == stack_len(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
