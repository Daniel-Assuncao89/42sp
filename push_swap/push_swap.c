/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:09:19 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/17 16:55:19 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "operations.h"
#include "algorithms.h"
#include "parse.h"
// #include <stdio.h>

// static void		test_stacks(t_stacks *stacks);
static float	compute_disorder(int *stack, int max_length);

// Simple algo is bugged for some reason -- DONE
// 		NEEDS TO BE DEBUGGED -- FIXED

// Needs to check if it is already ordered before applying algo -- DONE
// Needs to implement Medium Algo
// Needs to implement Complex Algo
// Needs to calculate disorder -- DONE
// Needs to implement switch statement for each Algo depending on disorder -- DONE / Still needs to be tested
// Needs to implement --bench logic
// 		Count each operation

// Convert Array to Linked List
// Time how long does it take to the whole operation to proccess to compare Array with Linked List
// Develop the Checker-Bonus
// Unit Tests for comparing the result of my Checker with the ones that we receive
static void	strategy_checker(t_input input, int max)
{
	t_stacks	stacks;

	stacks = init_stacks(input.values, input.size);
	print_stack(stacks, 'a');
	print_stack(stacks, 'b');
	if (input.strategy == STRATEGY_ADAPTIVE)
	{
		if (max < 20)
			apply_simple(&stacks);
		else if (max >= 20 && max < 50)
			ft_printf("Applying Medium Algorithm\n");
		else if (max >= 50)
			ft_printf("Applying Complex Algorithm\n");
	}
	else if (input.strategy == STRATEGY_SIMPLE)
		apply_simple(&stacks);
	else if (input.strategy == STRATEGY_MEDIUM)
		ft_printf("Applying Medium Algorithm\n");
	else if (input.strategy == STRATEGY_COMPLEX)
		ft_printf("Applying Complex Algorithm\n");
	print_stack(stacks, 'a');
	print_stack(stacks, 'b');
	// test_stacks(&stacks);
	free(stacks.stack_a);
	free(stacks.stack_b);
}

int	main(int ac, char **av)
{
	t_input		input;
	float		disorder;
	int			max;
	int			min;

	if (ac > 1)
	{
		if (!parse_input(ac, av, &input))
		{
			free_input(&input);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		print_input(&input);

		// Checar se já está ordenado
		// Se estiver, não printar nada
		// ft_printf("%s\n", is_ordered(input.values, input.size) ? "Ordered" : "NON-Ordered");

		disorder = compute_disorder(input.values, input.size);
		max = disorder * 100;
		min = ((int)(disorder * 10000)) % 100;
		ft_printf("Disorder: %d.%d\n", max, min);
		if (!(max == 0 && min == 0))
			strategy_checker(input, max);

		// ft_printf("Disorder: %d\n", (int)(disorder * 100));
		// ft_printf("Disorder: %d\n", ((int)(disorder * 10000) % 100));

		// if (!is_ordered(input.values, input.size))
		// {
		// 	stacks = init_stacks(input.values, input.size);
		// 	test_stacks(&stacks);
		// 	free(stacks.stack_a);
		// 	free(stacks.stack_b);
		// }
		free_input(&input);
	}
	return (0);
}

/*
static void test_stacks(t_stacks *stacks)
{
	// sa(stacks.stack_a, stacks.amount_a);
	// sb(stacks.stack_b, stacks.amount_b);
	// ss(&stacks);
	// pb(&stacks);
	// pa(&stacks);
	// ra(stacks.stack_a, stacks.amount_a);
	// rb(stacks.stack_b, stacks.amount_b);
	// rr(&stacks);
	// rra(stacks.stack_a, stacks.amount_a);
	// rrb(stacks.stack_b, stacks.amount_b);
	// rrr(&stacks);

	print_stack(*stacks, 'a');
	print_stack(*stacks, 'b');

	apply_simple(stacks);

	print_stack(*stacks, 'a');
	print_stack(*stacks, 'b');
}
*/

static float	compute_disorder(int *stack, int max_length)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	// ft_printf("Entered compute_disorder()\n");
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < max_length)
	{
		j = i + 1;
		while (j < max_length)
		{
			total_pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
