/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:43:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/11 16:38:03 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack -> next)
	{
		if (stack -> value > stack -> next -> value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

int	stacklen(t_stack_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack -> next;
	}
	return (len);
}

t_stack_node	*find_largest(t_stack_node *stack)
{
	t_stack_node	*largest_node;
	long			max;

	if (!stack)
		return (NULL);
	largest_node = stack;
	max = LONG_MIN;
	while (stack)
	{
		if (stack -> value > max)
		{
			max = stack -> value;
			largest_node = stack;
		}
		stack = stack -> next;
	}
	return (largest_node);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	long			min;

	if (!stack)
		return (NULL);
	smallest_node = stack;
	min = LONG_MAX;
	while (stack)
	{
		if (stack -> value < min)
		{
			min = stack -> value;
			smallest_node = stack;
		}
		stack = stack -> next;
	}
	return (smallest_node);
}

t_stack_node	*grab_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack -> next;
	}
	return (NULL);
}
