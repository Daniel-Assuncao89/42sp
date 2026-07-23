/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:41 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 01:28:29 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

// sa (swap a): Swap the first two elements at the top of stack a.
// 				Do nothing if there is only one or no elements.
void	sa(int *stack, int max_length, t_bench *bench);

// sb (swap b): Swap the first two elements at the top of stack b.
// 				Do nothing if there is only one or no elements.
void	sb(int *stack, int max_length, t_bench *bench);

// ss:	sa and sb at the same time.
void	ss(t_stacks *stacks, t_bench *bench);

// pa (push a): Take the first element at the top of b and put it
//				at the top of a.
// 				Do nothing if b is empty.
void	pa(t_stacks *stacks, t_bench *bench);

// pb (push b): Take the first element at the top of a and put it
//				at the top of b.
// 				Do nothing if a is empty.
void	pb(t_stacks *stacks, t_bench *bench);

// ra (rotate a):	Shift up all elements of stack a by one.
// 					The first element becomes the last one
void	ra(int *stack, int max_length, t_bench *bench);

// rb (rotate b): 	Shift up all elements of stack b by one.
// 					The first element becomes the last one
void	rb(int *stack, int max_length, t_bench *bench);

// rr:	ra and rb at the same time.
void	rr(t_stacks *stacks, t_bench *bench);

// rra (reverse rotate a):	Shift down all elements of stack a by one.
// 							The last element becomes the first one.
void	rra(int	*stack, int max_length, t_bench *bench);

// rrb (reverse rotate b):	Shift down all elements of stack b by one.
// 							The last element becomes the first one.
void	rrb(int	*stack, int max_length, t_bench *bench);

// rrr:	rra and rrb at the same time.
void	rrr(t_stacks *stacks, t_bench *bench);

#endif // OPERATIONS_H
