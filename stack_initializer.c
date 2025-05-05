/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 02:30:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 02:30:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	add_node(t_stack_node **stack, int num)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node -> value = num;
	node -> cheapest = 0;
	node -> next = NULL;
	if (!(*stack))
	{
		*stack = node;
		node -> prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node -> next = node;
		node -> prev = last_node;
	}
}
