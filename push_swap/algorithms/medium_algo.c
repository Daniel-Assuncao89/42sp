/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 02:38:21 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 17:36:26 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "libft.h"
#include "push_swap.h"
#include "operations.h"

static void		move_to_top_dup(int index, t_stack *stack);
static void		sort_back(t_stacks *stacks, t_stacks *dupli, t_bench *bench);
static void		push_chunk(t_stacks *sts, t_stacks *dup, int *bds, t_bench *be);

void	apply_medium(t_stacks *stacks, t_bench *bench)
{
	t_stacks	dup;
	int			chunk_size;
	int			bounds[2];

	dup = create_duplicate(&stacks->s_a);
	chunk_size = square_root(stacks->s_a.amount);
	bounds[0] = 0;
	bounds[1] = chunk_size - 1;
	while (stacks->s_a.amount > 0)
	{
		push_chunk(stacks, &dup, bounds, bench);
		bounds[0] += chunk_size;
		bounds[1] += chunk_size;
		if (dup.s_a.amount < chunk_size)
			bounds[1] = (bounds[0] + (dup.s_a.amount - 1));
	}
	sort_back(stacks, &dup, bench);
	free(dup.s_a.stack);
	free(dup.s_b.stack);
}

static void	move_to_top_dup(int index, t_stack *stack)
{
	int	swap;

	swap = stack->stack[index];
	if (index < ((stack->amount - 1) / 2))
		while (stack->stack[stack->amount - 1] != swap)
			rrx(stack);
	else
		while (stack->stack[stack->amount - 1] != swap)
			rx(stack);
}

static void	sort_back(t_stacks *stacks, t_stacks *dupli, t_bench *bench)
{
	int	major;

	major = dupli->s_b.amount - 1;
	while (major >= 0)
	{
		move_to_top(search_value(&dupli->s_b, major), &stacks->s_b, bench);
		move_to_top_dup(search_value(&dupli->s_b, major), &dupli->s_b);
		pa(stacks, bench);
		px(dupli, 'a');
		major--;
	}
}

static void	push_chunk(t_stacks *sts, t_stacks *dup, int *bds, t_bench *be)
{
	int	element_index;
	int	mid;

	mid = bds[0] + ((bds[1] - bds[0] + 1) / 2);
	while (dup->s_b.amount <= bds[1])
	{
		element_index = closer_element(&dup->s_a, bds[0], bds[1]);
		move_to_top(element_index, &sts->s_a, be);
		move_to_top_dup(element_index, &dup->s_a);
		pb(sts, be);
		px(dup, 'b');
		if (dup->s_b.stack[dup->s_b.amount - 1] < mid)
		{
			rb(&sts->s_b, be);
			rx(&dup->s_b);
		}
	}
}
