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

# include <stdbool.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack_node 
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	struct s_stack_node *target;
}	t_stack_node;

#endif