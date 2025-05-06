/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:20:52 by nanasser          #+#    #+#             */
/*   Updated: 2025/04/13 20:20:52 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	initialize_stack_a(&stack_a, av + 1);
	ft_lstclear(&stack_a);
	return (0);
}
