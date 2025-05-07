/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:06:03 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 19:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_val;

	biggest_val = find_largest(*a);
	if (biggest_val == *a)
		ra(a, false);
	else if ((*a)->next == biggest_val)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
