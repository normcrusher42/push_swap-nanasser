/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:29:57 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/05 02:03:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	error_check(char *str)
{
	if (!((*str == '-' || *str == '+') || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && !(*str >= '0' && *str <= '9'))
		return (1);
	while (++*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	dup_check(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a-> value == n)
			return (1);
		a = a -> next;
	}
	return (0);
}

void	free_check(t_stack_node **node)
{
	ft_lstclear(node);
	ft_printf("\n");
	exit(1);
}