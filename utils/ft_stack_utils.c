/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/05 12:56:29 by tmoumni          ###   ########.fr       */
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

	printf("-----\n");
	while (head)
	{
		printf("|%d|\t", head->value);
		printf("prc :(%d)\t", head->push_price);
		if(head->target_node_up)
			printf("[[trgUp: (%d)]]\t", head->target_node_up->value);
		if(head->target_node_down)
			printf("[[trgDown: (%d)]]\t", head->target_node_down->value);
		printf("istrg: (%d)\n", head->isTarget);
		head = head->next;
	}
	printf("-----\n");
}

int	is_sorted(t_stack_node *head)
{
	if (!head)
		return (0);
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
		head->isTarget = 0;
		head->current_pos = i;
		if (i > mid)
			head->above_median = 0;
		else
			head->above_median = 1;
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
	t_stack_node *small;

	small = small_node(*a);
	if (small->above_median)
	{
		while (small->value != (*a)->value)
			ra(a);
	}
	else
	{
		while (small->value != (*a)->value)
			rra(a);
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

void	sort_of_four(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *small = small_node(*a);
	if (small->above_median)
	{
		while (small->value != (*a)->value)
			ra(a);
	}
	else
	{
		while (small->value != (*a)->value)
			rra(a);
	}
	pb(b, a);
	sort_of_three(a);
	pa(a, b);
}

void	get_target_node_up(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	current_a = *a;
	while(current_a)
	{
		long diff = INT_MIN;
		current_b = *b;
		current_a->target_node_up = NULL;
		while (current_b)
		{
			if ((current_b)->value < current_a->value)
			{
				if ((current_b)->value - current_a->value > diff)
				{
					diff = (current_b)->value - current_a->value;
					if (!current_b->isTarget)
					{
						current_a->target_node_up = (current_b);
						current_b->isTarget = 1;
					}
				}
			}
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

void	get_target_node_down(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	current_a = *a;
	while(current_a)
	{
		long diff = INT_MAX;
		current_b = *b;
		current_a->target_node_down = NULL;
		while (current_b)
		{
			if ((current_b)->value > current_a->value)
			{
				if ((current_b)->value - current_a->value < diff)
				{
					diff = (current_b)->value - current_a->value;
					if (!current_b->isTarget)
					{
						current_a->target_node_down = (current_b);
						current_b->isTarget = 1;
					}
				}
			}
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

void	set_push_price(t_stack_node **stack)
{
	t_stack_node	*head;

	long			s_len;

	head = *stack;
	s_len = stack_len(head);

	while (head)
	{
		if (head->above_median)
			head->push_price = head->current_pos;
		else
			head->push_price = s_len - head->current_pos;
		head = head->next;
	}
}

t_stack_node	*sheap_node(t_stack_node **a)
{
	t_stack_node *curr_a = *a;
	t_stack_node *sheap_node;
	sheap_node = NULL;
	long max = INT_MAX;
	while (curr_a)
	{
		// printf("\n[[[%d]]]\n\n\n", curr_a->value);
		if (curr_a->target_node_up)
		{
			if (curr_a->value + curr_a->target_node_up->value < max)
			{
				max = curr_a->value + curr_a->target_node_up->value;
				sheap_node = curr_a;
			}
		}
		curr_a = curr_a->next;
	}
	return (sheap_node);
}

void	init_nodes(t_stack_node **a, t_stack_node **b)
{
	// get_target_node(b, a);
	set_position(*a);
	set_position(*b);
	set_push_price(a);
	set_push_price(b);
	
}

void	rotate_stack_a(t_stack_node **a)
{
	t_stack_node *sheap;

	sheap = sheap_node(a);
	if (sheap->above_median)
	{
		while ((*a)->value != sheap->value)
			ra(a);
	}
	else
	{
		while ((*a)->value != sheap->value)
			rra(a);
	}
}

void	rotate_stack_b(t_stack_node**a, t_stack_node **b)
{
	t_stack_node *sheap;

	sheap = sheap_node(a)->target_node_up;
	if (sheap->above_median)
	{
		while ((*b)->value != sheap->value)
			rb(b);
	}
	else
	{
		while ((*b)->value != sheap->value)
			rrb(b);
	}
}

int		has_targt_up(t_stack_node **stack)
{
	int	target = 0;
	t_stack_node *head = *stack;

	while(head)
	{
		if(head->target_node_up)
			target++;
		head = head->next;
	}
	return (target);
}

int		has_targt_down(t_stack_node **stack)
{
	int	target = 0;
	t_stack_node *head = *stack;

	while(head)
	{
		if(head->target_node_down)
			target++;
		head = head->next;
	}
	return (target);
}

void	fix_head(t_stack_node **stack, t_stack_node *head)
{
	t_stack_node *node = head;

	while ((*stack)->value != node->value)
	{
		if (node->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

void main_sort(t_stack_node **a, t_stack_node **b)
{
	init_nodes(a, b);
	get_target_node_up(a, b);
	while (has_targt_up(a))
	{
		draw_stack(*a);
		rotate_stack_a(a);
		rotate_stack_b(a, b);
		pa(a, b);
		fix_head(a, small_node(*a));
		init_nodes(a, b);
		get_target_node_up(a, b);
	}
	init_nodes(a, b);
	get_target_node_down(a, b);
	printf("[[[[[[[[[1]]]]]]]]]\n");
	draw_stack(*a);
	printf("[[[[[[[[[2]]]]]]]]]\n");
	while (has_targt_down(a))
	{
		draw_stack(*a);
		rotate_stack_a(a);
		rotate_stack_b(a, b);
		pa(a, b);
		fix_head(a, small_node(*a));
		init_nodes(a, b);
		get_target_node_down(a, b);
	}
}

