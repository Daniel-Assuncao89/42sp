/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:07:58 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:22:12 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	px(t_stacks *stacks, char dest)
{
	t_stack	*s_a;
	t_stack	*s_b;

	s_a = &stacks->s_a;
	s_b = &stacks->s_b;
	if (dest == 'b' && s_a->amount > 0)
	{
		s_b->stack[s_b->amount] = s_a->stack[s_a->amount - 1];
		s_b->amount++;
		s_a->amount--;
	}
	else if (dest == 'a' && s_b->amount > 0)
	{
		s_a->stack[s_a->amount] = s_b->stack[s_b->amount - 1];
		s_a->amount++;
		s_b->amount--;
	}
}

void	pa(t_stacks *stacks, t_bench *bench)
{
	px(stacks, 'a');
	bench->total_operations++;
	bench->count_pa++;
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks, t_bench *bench)
{
	px(stacks, 'b');
	bench->total_operations++;
	bench->count_pb++;
	ft_printf("pb\n");
}
