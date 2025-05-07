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

void print_list(t_stack_node *head)
{
	t_stack_node *temp = head;
	ft_printf("List: ");
	while (temp)
	{
		ft_printf("[%d] ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}

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
	if (!stack_a)
		return (1);
	if (!(stack_is_sorted(stack_a)))
	{
		if (stacklen(stack_a) == 2)
			sa(&stack_a, false);
		else if (stacklen(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&a, &b);
	}
	print_list(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
