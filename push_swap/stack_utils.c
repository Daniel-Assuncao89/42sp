/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:09:23 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 19:08:53 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	init_stacks(int values[], int length)
{
	t_stacks	stacks;
	int			i;

	stacks.max_length = length;
	stacks.stack_a = ft_calloc(length, sizeof(int));
	stacks.stack_b = ft_calloc(length, sizeof(int));
	stacks.amount_b = 0;
	i = 0;
	while (i++ < length)
		stacks.stack_a[i - 1] = values[length - i];
	stacks.amount_a = length;
	return (stacks);
}

// To be removed when the project is finished
void	print_stack(t_stacks stacks, char c)
{
	int	i;

	i = 0;
	ft_printf("Stack %c: ", c == 'a' ? 'A' : 'B');
	while (c == 'a' && i < stacks.amount_a)
		ft_printf("%d ", stacks.stack_a[i++]);
	while (c == 'b' && i < stacks.amount_b)
		ft_printf("%d ", stacks.stack_b[i++]);
	if (c == 'b')
		ft_printf("\n------------------------------");
	ft_printf("\n");
}

// Checks if given stacks is already ordered
// Inútil agora depois que implementei cálculo de disorder
// Remover futuramente
int	is_ordered(int nbs[], int size)
{
	int	i;

	if (size <= 1)
		return (1);
	i = 1;
	while (i++ < size)
		if (nbs[i - 1] < nbs[i - 2])
			return (0);
	return (1);
}
