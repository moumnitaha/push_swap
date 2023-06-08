/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:04:31 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/08 14:48:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_append_node(t_stack_node **stack_a, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = NULL;
	}
}

t_stack_node	*ft_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack_node	*big_node(t_stack_node *head)
{
	int				big_value;
	t_stack_node	*big_node;

	big_node = NULL;
	big_value = INT_MIN;
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->value >= big_value)
		{
			big_value = head->value;
			big_node = head;
		}
		head = head->next;
	}
	return (big_node);
}

t_stack_node	*small_node(t_stack_node *head)
{
	int				small_value;
	t_stack_node	*small_node;

	small_node = NULL;
	small_value = INT_MAX;
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->value <= small_value)
		{
			small_value = head->value;
			small_node = head;
		}
		head = head->next;
	}
	return (small_node);
}

int	stack_len(t_stack_node *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}
