/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:08:19 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/18 00:58:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	whitespaces(const char *str, int *istr)
{
	int	i;
	int	counter;

	i = 0;
	counter = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			counter *= -1;
		i++;
	}
	*istr = i;
	return (counter);
}

long	ft_atoi(const char *str, t_stack_node **node, char **av, bool tick)
{
	int			i;
	int			sign;
	long		result;

	sign = whitespaces(str, &i);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			free_check(node, av, tick);
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * sign);
}
