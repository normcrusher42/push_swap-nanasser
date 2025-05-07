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

#include "../swap.h"

void	curr_index(t_stack_node *stack)
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

void	init_a_to_b(t_stack_node *a, t_stack_node *b)
{
	curr_index(a);
	curr_index(b);
	
}