/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:09:23 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:18:54 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	init_stacks(int values[], int length)
{
	t_stacks	stacks;
	int			i;

	stacks.max_length = length;
	stacks.s_a.stack = ft_calloc(length, sizeof(int));
	stacks.s_b.stack = ft_calloc(length, sizeof(int));
	stacks.s_a.name = 'a';
	stacks.s_b.name = 'b';
	i = 0;
	while (i++ < length)
		stacks.s_a.stack[i - 1] = values[length - i];
	stacks.s_a.amount = length;
	stacks.s_b.amount = 0;
	return (stacks);
}

// To be removed when the project is finished
void	print_stack(const t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->name == 'a')
		ft_printf("Stack A: ");
	else
		ft_printf("Stack B: ");
	while (i < stack->amount)
		ft_printf("%d ", stack->stack[i++]);
	ft_printf("\n");
}

void	print_stacks(const t_stacks *stacks)
{
	ft_printf("\n***************************\n");
	print_stack(&stacks->s_a);
	print_stack(&stacks->s_b);
	ft_printf("***************************\n");
}
