/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:36:54 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 18:37:34 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"

void	move_to_top(int index, t_stack *stack, t_bench *bench)
{
	int	swap;

	swap = stack->stack[index];
	if (index < ((stack->amount - 1) / 2))
	{
		while (stack->stack[stack->amount - 1] != swap)
		{
			if (stack->name == 'a')
				rra(stack, bench);
			else
				rrb(stack, bench);
		}
	}
	else
	{
		while (stack->stack[stack->amount - 1] != swap)
		{
			if (stack->name == 'a')
				ra(stack, bench);
			else
				rb(stack, bench);
		}
	}
}

t_stacks	create_duplicate(t_stack *stack_a)
{
	t_stacks	duplicate;
	int			j;
	int			minor_index;

	duplicate.max_length = stack_a->amount;
	duplicate.s_a.name = 'a';
	duplicate.s_a.stack = ft_calloc(duplicate.max_length, sizeof(int));
	j = 0;
	minor_index = search_minor(stack_a);
	duplicate.s_a.stack[minor_index] = j;
	while (++j < duplicate.max_length)
	{
		minor_index = next_minor(stack_a, minor_index);
		duplicate.s_a.stack[minor_index] = j;
	}
	duplicate.s_a.amount = stack_a->amount;
	duplicate.s_b.name = 'b';
	duplicate.s_b.stack = ft_calloc(duplicate.max_length, sizeof(int));
	duplicate.s_b.amount = 0;
	return (duplicate);
}

