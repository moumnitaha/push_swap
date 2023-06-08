/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:44:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 15:00:59 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_commands(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a);
	if (!ft_strncmp(line, "sb\n", 3))
		sb(b);
	if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b);
	if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a);
	if (!ft_strncmp(line, "ra\n", 3))
		ra(a);
	if (!ft_strncmp(line, "rb\n", 3))
		rb(b);
	if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	if (!ft_strncmp(line, "rra\n", 4))
		rra(a);
	if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b);
	if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
}

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
		parse_commands(line, &a, &b);
		line = get_next_line(fd);
	}
	if (is_sorted(a) && len == stack_len(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
