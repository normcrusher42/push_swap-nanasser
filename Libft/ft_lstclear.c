/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:07:15 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/05 20:17:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

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
