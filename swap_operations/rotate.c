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

static void	rotate(t_stack_node **headchef)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!headchef || !*headchef || !(*headchef)->next)
		return ;
	first = *headchef;
	last = ft_lstlast(*headchef);
	*headchef = first -> next;
	(*headchef)->prev = NULL;
	last -> next = first;
	first -> prev = last;
	first -> next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
