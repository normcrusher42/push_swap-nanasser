/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:35:03 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 19:35:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

// static void	rrotate(t_stack_node **headchef)
// {
// 	t_stack_node	*second_last;
// 	t_stack_node	*last;

// 	if (!headchef || !*headchef || !(*headchef)->next)
// 		return ;
// 	last = ft_lstlast(*headchef);
// 	second_last = last -> prev;
// 	second_last -> next = NULL;
// 	last -> prev = NULL;
// 	last -> next = *headchef;
// 	(*headchef)->prev = last;
// 	*headchef = last;
// }

static void	rrotate(t_stack_node **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack_node	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack_node **a, bool print)
{
	rrotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rrotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rrotate(a);
	rrotate(b);
	if (!print)
		ft_printf("rrr\n");
}
