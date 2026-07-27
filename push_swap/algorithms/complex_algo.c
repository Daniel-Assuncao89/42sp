/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:41:55 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/23 14:43:31 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "push_swap.h"
#include "operations.h"

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static int	get_top_a(t_stacks *stacks)
{
	return (stacks->s_a.stack[stacks->s_a.amount - 1]);
}

static void	radix_pass(t_stacks *stacks, t_bench *bench, int bit)
{
	int	i;
	int	size;
	int	top;

	i = 0;
	size = stacks->s_a.amount;
	while (i < size)
	{
		top = get_top_a(stacks);
		if (((top >> bit) & 1) == 0)
			pb(stacks, bench);
		else
			ra(&stacks->s_a, bench);
		i++;
	}
	while (stacks->s_b.amount > 0)
		pa(stacks, bench);
}

void	apply_complex(t_stacks *stacks, t_bench *bench)
{
	int	bit;
	int	max_bits;

	if (stacks->s_a.amount <= 1)
		return ;
	if (!normalize_to_ranks(stacks))
		return ;
	bit = 0;
	max_bits = get_max_bits(stacks->s_a.amount);
	while (bit < max_bits)
	{
		radix_pass(stacks, bench, bit);
		bit++;
	}
}
