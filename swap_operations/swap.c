/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:28:54 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 02:28:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

static void	swap(t_stack_node **headchef)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!headchef || !*headchef || !(*headchef) -> next)
		return ;
	first = *headchef;
	second = first -> next;
	first -> next = second -> next;
	if (second -> next)
		second -> next -> prev = first;
	second -> prev = NULL;
	second -> next = first;
	first -> prev = second;
	*headchef = second;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}