/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:08:11 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:08:11 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	rrx(int	*stack, int max_length)
{
	int	swap;
	int	i;
	int	last_index;

	if (max_length > 1)
	{
		last_index = (max_length - 1);
		i = 0;
		swap = stack[i];
		while (i++ < last_index)
			stack[i - 1] = stack[i];
		stack[last_index] = swap;
	}
}

void	rra(int	*stack, int max_length)
{
	rrx(stack, max_length);
	ft_printf("rra\n");
}

void	rrb(int	*stack, int max_length)
{
	rrx(stack, max_length);
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rrx(stacks->stack_a, stacks->amount_a);
	rrx(stacks->stack_b, stacks->amount_b);
	ft_printf("rrr\n");
}
