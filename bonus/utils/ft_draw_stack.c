/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:59:55 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 16:07:46 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_checker.h"

void	draw_stack(t_stack_node *head)
{
	ft_printf("-----\n");
	while (head)
	{
		ft_printf("|%d|\n", head->value);
		head = head->next;
	}
	ft_printf("-----\n");
}
