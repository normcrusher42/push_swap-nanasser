/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:07:15 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/11 16:38:03 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*move;
	t_stack_node	*temp;

	if (!*lst)
		return ;
	move = *lst;
	while (move)
	{
		temp = move -> next;
		move -> value = 0;
		free(move);
		move = temp;
	}
	*lst = NULL;
}
