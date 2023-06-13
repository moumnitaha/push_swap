/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:44:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/13 14:25:29 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_status(t_stack_node *a, int len)
{
	if (is_sorted(a) && len == stack_len(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
}

void	exit_err_arg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_commands(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
	else
		exit_error(a, b);
}

int	main(int ac, char **av)
{
	char			*line;
	int				len;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(0);
	if (ac > 1 && !av[1][0])
		exit_err_arg();
	split_args(ac, av, &a);
	len = stack_len(a);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		parse_commands(line, &a, &b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	print_status(a, len);
	return (0);
}
