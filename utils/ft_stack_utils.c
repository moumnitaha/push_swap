/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:14:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/06/04 18:50:49 by tmoumni          ###   ########.fr       */
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
		if(head->target_node)
			printf("[[trg: (%d)]]\t", head->target_node->value);
		printf("mid: (%d)\n", head->above_median);
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

void	get_target_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	current_a = *a;
	while(current_a)
	{
		long diff = INT_MIN;
		current_b = *b;
		while (current_b)
		{
			if ((current_b)->value < current_a->value)
			{
				if ((current_b)->value - current_a->value > diff)
				{
					diff = (current_b)->value - current_a->value;
					current_a->target_node = (current_b);
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

/////////////////////

// void	set_target_node(t_stack_node *a, t_stack_node *b)
// {
// 	t_stack_node	*current_a;
// 	t_stack_node	*target_node;
// 	long			best_match_index;

// 	while (b)
// 	{
// 		best_match_index = LONG_MAX;
// 		current_a = a;
// 		while (current_a)
// 		{
// 			if (current_a->value > b->value
// 				&& current_a->value < best_match_index)
// 			{
// 				best_match_index = current_a->value;
// 				target_node = current_a;
// 			}
// 			current_a = current_a->next;
// 		}
// 		if (LONG_MAX == best_match_index)
// 			b->target_node = find_smallest(a);
// 		else
// 			b->target_node = target_node;
// 		b = b->next;
// 	}
// }

// void	set_price(t_stack_node *a, t_stack_node *b)
// {
// 	int	len_a;
// 	int	len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while (b)
// 	{
// 		b->push_price = b->current_pos;
// 		if (!(b->above_median))
// 			b->push_price = len_b - (b->current_pos);
// 		if (b->target_node->above_median)
// 			b->push_price += b->target_node->current_pos;
// 		else
// 			b->push_price += len_a - (b->target_node->current_pos);
// 		b = b->next;
// 	}
// }

// void	set_cheapest(t_stack_node *b)
// {
// 	long			best_match_value;
// 	t_stack_node	*best_match_node;

// 	if (NULL == b)
// 		return ;
// 	best_match_value = LONG_MAX;
// 	while (b)
// 	{
// 		if (b->push_price < best_match_value)
// 		{
// 			best_match_value = b->push_price;
// 			best_match_node = b;
// 		}
// 		b = b->next;
// 	}
// 	best_match_node->cheapest = true;
// }

// void	init_nodes(t_stack_node *a, t_stack_node *b)
// {
// 	set_position(a);
// 	set_position(b);
// 	set_target_node(a, b);
// 	set_price(a, b);
// 	set_cheapest(b);
// }

//////////////