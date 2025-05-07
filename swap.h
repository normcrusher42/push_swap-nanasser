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

//The Holy Grail of this whole operation
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

//initializing stack """A"""
void			initialize_stack_a(t_stack_node **node, char **av);
int				ft_atoi(const char *str, t_stack_node **node);

//Error checking and Handling
int				error_check(char *str);
int				dup_check(t_stack_node *a, int n);
void			free_check(t_stack_node **node);

//Node ogranizing
void			add_node(t_stack_node **stack, int num);
void			ft_lstclear(t_stack_node **lst);
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				stacklen(t_stack_node *stack);

//Stack sorcery
bool			stack_is_sorted(t_stack_node *stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

#endif
