/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:29:57 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/11 19:42:25 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
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

void	free_check(t_stack_node **node, char **av, bool tick)
{
	ft_lstclear(node);
	if (tick)
		free_split_result(av - 1);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
