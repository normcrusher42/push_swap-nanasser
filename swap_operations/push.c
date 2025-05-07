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