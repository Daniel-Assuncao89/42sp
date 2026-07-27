/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:38:21 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/23 14:38:34 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(int *stack, int size, int value)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < size)
	{
		if (stack[i] < value)
			rank++;
		i++;
	}
	return (rank);
}

static void	copy_stack(int *src, int *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	apply_ranks(int *stack, int *copy, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = get_rank(copy, size, stack[i]);
		i++;
	}
}

int	normalize_to_ranks(t_stacks *stacks)
{
	int	*copy;

	copy = malloc(sizeof(int) * stacks->s_a.amount);
	if (!copy)
		return (0);
	copy_stack(stacks->s_a.stack, copy, stacks->s_a.amount);
	apply_ranks(stacks->s_a.stack, copy, stacks->s_a.amount);
	free(copy);
	return (1);
}
