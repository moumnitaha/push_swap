/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/04 00:02:33 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*ft_find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

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
		last_node = ft_find_last_node(*stack_a);
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = NULL;
	}
}

int	ft_error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!i && (str[0] == '-' || str[0] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_error_repitition(char **av, int nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nbr)
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	int_check(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

void	draw_stack(t_stack_node *head)
{
	t_stack_node	*last;

	last = ft_find_last_node(head);
	printf("-----\n");
	while (last)
	{
		printf("|%d|\t", last->value);
		// printf("pos: (%d)\t", last->current_pos);
		printf("mid: (%d)\n", last->above_median);
		last = last->prev;
	}
	printf("-----\n");
}

int	is_sorted(t_stack_node *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
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

void	set_position(t_stack_node *head)
{
	int	mid;
	int i;

	mid = stack_len(head) / 2;
	i = 0;
	while (head)
	{
		head->current_pos = i;
		if (i >= mid)
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
		i++;
	}
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

void	sort_of_three(t_stack_node **head)
{
	t_stack_node 	*big;

	big = big_node(*head);
	if (*head == big)
		ra(head);
	if ((*head)->next == big)
		rra(head);
	if ((*head)->next == small_node(*head))
		sa(head);
}

void	push_2_big_vals(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *big;

	big = big_node(*a);
	if (big->above_median)
	{
		while (big->value != ft_find_last_node(*a)->value)
			rra(a);
	}
	else
	{
		while (big->value != ft_find_last_node(*a)->value)
			ra(a);
	}
	pb(b, a);
}

void	sort_of_five(t_stack_node **a, t_stack_node **b)
{
	
	push_2_big_vals(a, b);
	set_position(*a);
	push_2_big_vals(a, b);
	sort_of_three(a);
	while (*b)
		pa(a, b);
}
