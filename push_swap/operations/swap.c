/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:07:53 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:22:49 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	sx(t_stack *stack)
{
	int	swap;
	int	last;

	last = (stack->amount - 1);
	if ((stack->amount) > 1)
	{
		swap = stack->stack[last];
		stack->stack[last] = stack->stack[last - 1];
		stack->stack[last - 1] = swap;
	}
}

void	sa(t_stack *stack, t_bench *bench)
{
	sx(stack);
	bench->total_operations++;
	bench->count_sa++;
	ft_printf("sa\n");
}

void	sb(t_stack *stack, t_bench *bench)
{
	sx(stack);
	bench->total_operations++;
	bench->count_sb++;
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks, t_bench *bench)
{
	sx(&stacks->s_a);
	sx(&stacks->s_b);
	bench->total_operations++;
	bench->count_ss++;
	ft_printf("ss\n");
}
