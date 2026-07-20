/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:35 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 02:38:07 by hequeiro         ###   ########.fr       */
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
// void	apply_simple(t_stacks *stacks);
void	apply_simple(t_stacks *stacks, t_bench *bench);
void	apply_medium(t_stacks *stacks, t_bench *bench);

int		search_minor(int *stack, int max_length);
// void	move_to_top(int index, int *stack, int max_length);
void	move_to_top(int index, int *stack, int max_length, t_bench *bench);

#endif // ALGORITHMS_H
