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
void			initialize_stack_a(t_stack_node **node, char **av, bool tick);
long			ft_atoi(const char *str, t_stack_node **node);

//Error checking and Handling
int				error_check(char *str);
int				dup_check(t_stack_node *a, int n);
void			free_check(t_stack_node **node);

//Node ogranizing
void			add_node(t_stack_node **stack, int num);
void			ft_lstclear(t_stack_node **lst);
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				stacklen(t_stack_node *stack);
t_stack_node	*find_largest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
void			set_median_index(t_stack_node *stack);
t_stack_node	*grab_cheapest(t_stack_node *stack);

///   Stack Sorcery Isle   ///
bool			stack_is_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			prep_push(t_stack_node **stack, t_stack_node *top_node,
					char stackname);
void			min_top(t_stack_node **a);

// swap
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
//rotate && reverse rotate
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
// Pushups //
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);

// Intializing nodes
void			init_a_to_b(t_stack_node *a, t_stack_node *b);
void			init_b_to_a(t_stack_node *b, t_stack_node *a);

#endif
