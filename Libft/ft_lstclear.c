/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:07:15 by nanasser          #+#    #+#             */
/*   Updated: 2025/05/05 01:05:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*move;
	t_list	*temp;

	if (!*lst)
		return ;
	move = *lst;
	while (move)
	{
		temp = move -> next;
		move -> content = 0;
		free(move);
		move = temp;
	}
	*lst = NULL;
}
