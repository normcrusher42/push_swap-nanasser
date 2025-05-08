/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:34:41 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 00:34:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest_node)
{
	while (*b != cheapest_node -> target && *a != cheapest_node)
		rr(a, b, false);
	set_median_index(*a);
	set_median_index(*b);
}

static void	rrotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest_node)
{
	while (*b != cheapest_node -> target && *a != cheapest_node)
		rrr(a, b, false);
	set_median_index(*a);
	set_median_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = grab_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rrotate_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target, 'b');
	pb(a, b, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stacklen(*a);
	if (a_len-- > 3 && !stack_is_sorted(*a))
		pb(a, b, false);
	if (a_len-- > 3 && !stack_is_sorted(*a))
		pb(a, b, false);
	while (a_len-- > 3 && !stack_is_sorted(*a))
	{
		init_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b_to_a(*b, *a);
		move_b_to_a(a, b);
	}
	set_median_index(*a);
	min_top(a);
}
