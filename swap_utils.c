/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:43:44 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 00:44:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	initialize_stack_a(t_stack_node **node, char **av)
{
	long	num;
	int		i;

	i = 0;
	write(1, "in function\n", 12);
	while (av[i])
	{
		if (error_check(av[i]))
		{
			write(1, "1 error here\n", 13);
			free_check(node);
		}
		if (!(ft_atoi(av[i])))
		{
			write(1, "2 error here\n", 13);
			free_check(node);
		}
		num = ft_atoi(av[i]);
		if (dup_check(*node, (int)num))
		{
			write(1, "3 error here\n", 13);
			free_check(node);
		}
		add_node(node, (int)num);
		i++;
	}
}
