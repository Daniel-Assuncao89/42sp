/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:04:11 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:54:28 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"

// Simple:
// Search minor number in Stack A	-- DONE
// Move it to the top of Stack A	-- DONE
// 		IF index is in at bottom half of the stack, rotate stack DOWNWARDS
// 		IF index is in at top half of the stack, rotate stack UPWARDS
// Push it to Stack B				-- DONE
// Repeat until Stack A is empty	-- DONE
// Push all numbers back to Stack A

void	apply_simple(t_stacks *stacks)
{
	int	minor_index;

	ft_printf("Applying Simple Algorithm\n");
	// Passo 4
	while (stacks->amount_a > 1)
	{
		// Passo 1
		minor_index = search_minor(stacks->stack_a, stacks->amount_a);
		// ft_printf("Minor Index in A: %d\n", minor_index);
		// ft_printf("Minor Value in A: %d\n", stacks->stack_a[minor_index]);
		// ft_printf("--------------------------\n");

		// Passo 2
		move_to_top(minor_index, stacks->stack_a, stacks->amount_a);

		// Passo 3
		pb(stacks);
	}
	// Passo 5
	while (stacks->amount_b > 0)
		pa(stacks);
}

// Returns index of minor number in given Stack
int	search_minor(int *stack, int max_length)
{
	int	minor;
	int	i;

	if (max_length == 0)
		return (-1);
	minor = 0;
	i = 0;
	while (i < max_length)
	{
		if (stack[i] < stack[minor])
			minor = i;
		i++;
	}
	return (minor);
}

// Moves it to the top of Stack A
// 		IF index is in at bottom half of the stack, rotate stack DOWNWARDS
// 		IF index is in at top half of the stack, rotate stack UPWARDS
void	move_to_top(int index, int *stack, int max_length)
{
	int	swap;

	swap = stack[index];
	if (index < ((max_length - 1) / 2))
		while (stack[max_length - 1] != swap)
			rra(stack, max_length);
	else
		while (stack[max_length - 1] != swap)
			ra(stack, max_length);
}
