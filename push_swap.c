/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:39:41 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/04 19:52:49 by tmoumni          ###   ########.fr       */
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
		exit(0);
	if (stack_len(a) == 2)
		sa(&a);
	if (stack_len(a) == 3)
		sort_of_three(&a);
	if (stack_len(a) == 4)
		sort_of_four(&a, &b);
	if (stack_len(a) == 5)
		sort_of_five(&a, &b);
	if (stack_len(a) > 5)
	{
		while (stack_len(a) > 3)
			pb(&b, &a);
		sort_of_three(&a);
		get_target_node(&a, &b);
		get_target_node(&b, &a);
		set_position(a);
		set_position(b);
		set_push_price(&a);
		set_push_price(&b);
		t_stack_node *h = a;
		t_stack_node *start;
		start = NULL;
		long max = INT_MAX;
		while (h)
		{
			if (h->push_price + h->target_node->push_price < max)
			{
				max = h->push_price + h->target_node->push_price;
				start = h;
			}
			h = h->next;
		}
		ft_printf("%d - %d", start->value, start->target_node->value);
		while (a->value != start->value)
		{
			ra(a);
		}
	}
	draw_stack(a);
	draw_stack(b);
	return (0);
}
