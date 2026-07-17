/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:41 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:01:42 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

// sa (swap a): Swap the first two elements at the top of stack a.
// 				Do nothing if there is only one or no elements.
void		sa(int *stack, int max_length);

// sb (swap b): Swap the first two elements at the top of stack b.
// 				Do nothing if there is only one or no elements.
void		sb(int *stack, int max_length);

// ss:	sa and sb at the same time.
void		ss(t_stacks *stacks);

// pa (push a): Take the first element at the top of b and put it
//				at the top of a.
// 				Do nothing if b is empty.
void		pa(t_stacks *stacks);

// pb (push b): Take the first element at the top of a and put it
//				at the top of b.
// 				Do nothing if a is empty.
void		pb(t_stacks *stacks);

// ra (rotate a):	Shift up all elements of stack a by one.
// 					The first element becomes the last one
void		ra(int *stack, int max_length);

// rb (rotate b): 	Shift up all elements of stack b by one.
// 					The first element becomes the last one
void		rb(int *stack, int max_length);

// rr:	ra and rb at the same time.
void		rr(t_stacks *stacks);

// rra (reverse rotate a):	Shift down all elements of stack a by one.
// 							The last element becomes the first one.
void		rra(int	*stack, int max_length);

// rrb (reverse rotate b):	Shift down all elements of stack b by one.
// 							The last element becomes the first one.
void		rrb(int	*stack, int max_length);

// rrr:	rra and rrb at the same time.
void		rrr(t_stacks *stacks);

#endif // OPERATIONS_H
