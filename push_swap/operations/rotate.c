/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:08:06 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:22:44 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rx(t_stack *stack)
{
	int	swap;
	int	last_index;

	if (stack->amount > 1)
	{
		last_index = (stack->amount - 1);
		swap = stack->stack[last_index];
		while (last_index-- > 0)
			stack->stack[last_index + 1] = stack->stack[last_index];
		stack->stack[0] = swap;
	}
}

void	ra(t_stack *stack, t_bench *bench)
{
	rx(stack);
	bench->total_operations++;
	bench->count_ra++;
	ft_printf("ra\n");
}

void	rb(t_stack *stack, t_bench *bench)
{
	rx(stack);
	bench->total_operations++;
	bench->count_rb++;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks, t_bench *bench)
{
	rx(&stacks->s_a);
	rx(&stacks->s_b);
	bench->total_operations++;
	bench->count_rr++;
	ft_printf("rr\n");
}
