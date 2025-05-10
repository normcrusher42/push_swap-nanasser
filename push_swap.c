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

// void print_list(t_stack_node *head)
// {
// 	t_stack_node *temp = head;
// 	ft_printf("List: ");
// 	while (temp)
// 	{
// 		ft_printf("[%d] ", temp->value);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }

static void	sort_if_needed(t_stack_node **a, t_stack_node **b)
{
	if (!(stack_is_sorted(*a)))
	{
		if (stacklen(*a) == 2)
			sa(a, false);
		else if (stacklen(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}


int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	bool tick;

	stack_a = NULL;
	stack_b = NULL;
	tick = false;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		tick = true;
	}
	initialize_stack_a(&stack_a, av + 1, tick);
	if (!stack_a)
		return (1);
	sort_if_needed(&stack_a, &stack_b);
	// print_list(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
