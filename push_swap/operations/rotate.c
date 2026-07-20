/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:08:06 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 01:34:57 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	rx(int *stack, int max_length)
{
	int	swap;
	int	last;

	if ((max_length) > 1)
	{
		last = (max_length - 1);
		swap = stack[last];
		while (last-- > 0)
			stack[last + 1] = stack[last];
		stack[0] = swap;
	}
}

void	ra(int *stack, int max_length, t_bench *bench)
{
	rx(stack, max_length);
	bench->total_operations++;
	bench->count_ra++;
	ft_printf("ra\n");
}

void	rb(int *stack, int max_length, t_bench *bench)
{
	rx(stack, max_length);
	bench->total_operations++;
	bench->count_rb++;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks, t_bench *bench)
{
	rx(stacks->stack_a, stacks->amount_a);
	rx(stacks->stack_b, stacks->amount_b);
	bench->total_operations++;
	bench->count_rr++;
	ft_printf("rr\n");
}
