/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:07:53 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:07:53 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	sx(int *stack, int max_length)
{
	int	swap;
	int	last;

	last = (max_length - 1);
	if ((max_length) > 1)
	{
		swap = stack[last];
		stack[last] = stack[last - 1];
		stack[last - 1] = swap;
	}
}

void	sa(int *stack, int max_length)
{
	sx(stack, max_length);
	ft_printf("sa\n");
}

void	sb(int *stack, int max_length)
{
	sx(stack, max_length);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	sx(stacks->stack_a, stacks->amount_a);
	sx(stacks->stack_b, stacks->amount_b);
	ft_printf("ss\n");
}
