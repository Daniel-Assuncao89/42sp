/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:04:11 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 17:28:12 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"

void	apply_simple(t_stacks *stacks, t_bench *bench)
{
	int	minor_index;

	while ((stacks->s_a.amount) > 1)
	{
		minor_index = search_minor(&stacks->s_a);
		move_to_top(minor_index, &stacks->s_a, bench);
		pb(stacks, bench);
	}
	while ((stacks->s_b.amount) > 0)
		pa(stacks, bench);
}
