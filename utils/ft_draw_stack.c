/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:55 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/10 18:04:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	draw_stack(t_stack_node *head)
{
	ft_printf("-----\n");
	while (head)
	{
		ft_printf("|%d|\t", head->value);
		ft_printf("i: (%d)\t", head->index);
		ft_printf("pos: (%d)\n", head->current_pos);
		head = head->next;
	}
	ft_printf("-----\n");
}
