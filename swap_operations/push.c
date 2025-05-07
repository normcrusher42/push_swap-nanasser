/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:49:01 by marvin            #+#    #+#             */
/*   Updated: 2025/05/08 00:49:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node -> next;
	if (*src)
		(*src) -> prev = NULL;
	node -> prev = NULL;
	if (!*dst)
	{
		*dst = node;
		node -> next = NULL;
	}
	else
	{
		node -> next = (*dst);
		(*dst) -> prev = NULL;
		node = *dst;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}