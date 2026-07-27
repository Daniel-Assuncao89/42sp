/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:08:11 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:22:20 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrx(t_stack *stack)
{
	int	swap;
	int	i;
	int	last_index;

	if (stack->amount > 1)
	{
		last_index = (stack->amount - 1);
		i = 0;
		swap = stack->stack[i];
		while (i++ < last_index)
			stack->stack[i - 1] = stack->stack[i];
		stack->stack[last_index] = swap;
	}
}

void	rra(t_stack *stack, t_bench *bench)
{
	rrx(stack);
	bench->total_operations++;
	bench->count_rra++;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack, t_bench *bench)
{
	rrx(stack);
	bench->total_operations++;
	bench->count_rrb++;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks, t_bench *bench)
{
	rrx(&stacks->s_a);
	rrx(&stacks->s_b);
	bench->total_operations++;
	bench->count_rrr++;
	ft_printf("rrr\n");
}
