/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:07:58 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 01:30:09 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_stacks *stacks, t_bench *bench)
{
	int	*amount_a;
	int	*amount_b;
	int	*stack_a;
	int	*stack_b;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	amount_a = &(stacks->amount_a);
	amount_b = &(stacks->amount_b);
	if (*amount_b > 0)
	{
		stack_a[*amount_a] = stack_b[*amount_b - 1];
		(*amount_a)++;
		(*amount_b)--;
		bench->total_operations++;
		bench->count_pa++;
	}
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks, t_bench *bench)
{
	int	*amount_a;
	int	*amount_b;
	int	*stack_a;
	int	*stack_b;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	amount_a = &(stacks->amount_a);
	amount_b = &(stacks->amount_b);
	if (*amount_a > 0)
	{
		stack_b[*amount_b] = stack_a[*amount_a - 1];
		(*amount_b)++;
		(*amount_a)--;
		bench->total_operations++;
		bench->count_pb++;
	}
	ft_printf("pb\n");
}
