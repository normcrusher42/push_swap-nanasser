/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:43:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 02:39:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	initialize_stack_a(t_stack_node **node, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_check(av[i]))
			free_check(node);
		num = ft_atoi(av[i]);
		if (num <= 0)
			free_check(node);
		if (dup_check(*node, (int)num))
			free_check(node);
		add_node(node, num);
		i++;
	}
}