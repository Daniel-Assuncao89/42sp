/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:08:06 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:08:06 by hequeiro         ###   ########.fr       */
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

void	ra(int *stack, int max_length)
{
	rx(stack, max_length);
	ft_printf("ra\n");
}

void	rb(int *stack, int max_length)
{
	rx(stack, max_length);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rx(stacks->stack_a, stacks->amount_a);
	rx(stacks->stack_b, stacks->amount_b);
	ft_printf("rr\n");
}
