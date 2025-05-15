/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:13:50 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 21:13:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_node_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*curr_a;
	long			closest_cost;

	while (b)
	{
		closest_cost = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < closest_cost)
			{
				target_node = curr_a;
				closest_cost = curr_a -> value;
			}
			curr_a = curr_a -> next;
		}
		if (closest_cost == LONG_MAX)
			b -> target = find_smallest(a);
		else
			b -> target = target_node;
		b = b -> next;
	}
}

void	init_b_to_a(t_stack_node *b, t_stack_node *a)
{
	set_median_index(a);
	set_median_index(b);
	target_node_b(a, b);
}
