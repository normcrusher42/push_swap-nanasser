/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:40:15 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 01:40:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	set_median_index(t_stack_node *stack)
{
	int	median;
	int	i;

	if (!stack)
		return ;
	median = stacklen(stack) / 2;
	i = 0;
	while (stack)
	{
		stack -> index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack -> next;
		i++;
	}
}

static void	target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target;
	t_stack_node	*curr_b;
	long			closest_cost;

	while (a)
	{
		closest_cost = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > closest_cost)
			{
				target = curr_b;
				closest_cost = curr_b -> value;
			}
			curr_b = curr_b -> next;
		}
		if (closest_cost == LONG_MIN)
			a -> target = find_largest(b);
		else
			a -> target = target;
		a = a -> next;
	}
}

static void	check_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stacklen(a);
	len_b = stacklen(b);
	while (a)
	{
		a -> push_cost = a -> index;
		if (!(a->above_median))
			a -> push_cost = len_a - (a->index);
		if (a->target->above_median)
			a -> push_cost += a -> target -> index;
		else
			a -> push_cost += len_b - (a->target->index);
		a = a -> next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_cost;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack -> next;
	}
	cheapest_node -> cheapest = true;
}

void	init_a_to_b(t_stack_node *a, t_stack_node *b)
{
	set_median_index(a);
	set_median_index(b);
	target_a(a, b);
	check_cost_a(a, b);
	set_cheapest(a);
}
