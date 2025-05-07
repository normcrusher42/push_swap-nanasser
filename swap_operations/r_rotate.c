/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:35:03 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 19:35:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

static void	rrotate(t_stack_node **headchef)
{
	t_stack_node	*second_last;
	t_stack_node	*last;

	if (!headchef || !*headchef || !(*headchef)->next)
		return ;
	last = ft_lstlast(*headchef);
	second_last = last -> prev;
	second_last -> next = NULL;
	last -> prev = NULL;
	last -> next = *headchef;
	(*headchef)->prev = last;
	*headchef = last;
}

void	rra(t_stack_node **a, bool print)
{
	rrotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rrotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rrotate(a);
	rrotate(b);
	if (!print)
		ft_printf("rrr\n");
}
