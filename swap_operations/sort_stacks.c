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

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stacklen(*a);
	if (a_len-- > 3 && !stack_is_sorted(a))
		pb(a, b, false);
	if (a_len-- > 3 && !stack_is_sorted(a))
		pb(a, b, false);
	
}