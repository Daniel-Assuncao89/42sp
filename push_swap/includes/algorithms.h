/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:35 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:12:57 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"

// Simple:
// Search minor number in Stack A
// Move it to the top of Stack A
// Push it to Stack B
// Repeat until Stack A is empty
// Push all numbers back to Stack A
void		apply_simple(t_stacks *stacks, t_bench *bench);
void		apply_medium(t_stacks *stacks, t_bench *bench);
void		apply_complex(t_stacks *stacks, t_bench *bench);

int			search_minor(const t_stack *stack);
void		move_to_top(int index, t_stack *stack, t_bench *bench);

// General Algorithm Utility Functions
int			search_value(t_stack *stack, int value);
int			square_root(int nb);
int			next_minor(const t_stack *stack, int current_minor);
int			closer_element(t_stack *stack, int lower_bound, int upper_bound);
t_stacks	create_duplicate(t_stack *stack_a);
int         normalize_to_ranks(t_stacks *stacks);

#endif // ALGORITHMS_H
