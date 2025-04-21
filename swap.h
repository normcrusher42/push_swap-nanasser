/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nanasser <nanasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:20:50 by nanasser          #+#    #+#             */
/*   Updated: 2025/04/13 20:20:50 by nanasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SWAP_H
# define SWAP_H

typedef struct s_list
{
	int		data;
	s_list	*next;
	s_list	*prev;
}	t_list;

#endif