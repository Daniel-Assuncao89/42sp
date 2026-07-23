/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:09:19 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 02:37:55 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithms.h"
#include "parse.h"

static float	compute_disorder(int *stack, int max_length);
static void		strategy_checker(t_input *input, t_bench *bench);
static void		init_bench(t_bench *bench, t_input *input);
static void		print_bench(t_bench *bench);

// Needs to implement Medium Algo
// Needs to implement Complex Algo
// Needs to implement switch statement for each Algo depending on disorder -- DONE / Still needs to be tested
// Needs to implement --bench logic -- SEMI-DONE
// 		Count each operation -- DONE

// Create new type that contains stack values and amount

// Convert Array to Linked List
// Time how long does it take to the whole operation to proccess to compare Array with Linked List
// Develop the Checker-Bonus
// Unit Tests for comparing the result of my Checker with the ones that we receive

int	main(int ac, char **av)
{
	t_input	input;
	t_bench	bench;

	if (ac > 1)
	{
		if (!parse_input(ac, av, &input))
		{
			free_input(&input);
			ft_putendl_fd("Error", 2);
			return (1);
		}
		print_input(&input);
		init_bench(&bench, &input);
		if (!(bench.disorder_max == 0 && bench.disorder_min == 0))
			strategy_checker(&input, &bench);
		free_input(&input);
		print_bench(&bench);
	}
	return (0);
}

static float	compute_disorder(int *stack, int max_length)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

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

static void		strategy_checker(t_input *input, t_bench *bench)
{
	t_stacks	stacks;

	stacks = init_stacks(input->values, input->size);
	print_stack(stacks, 'a');
	print_stack(stacks, 'b');
	if (input->strategy == STRATEGY_ADAPTIVE)
	{
		if (bench->disorder_max < 20)
			apply_simple(&stacks, bench);
		else if (bench->disorder_max >= 20 && bench->disorder_max < 50)
			apply_medium(&stacks, bench);
		else if (bench->disorder_max >= 50)
			ft_printf("Applying Complex Algorithm\n");
	}
	else if (input->strategy == STRATEGY_SIMPLE)
		apply_simple(&stacks, bench);
	else if (input->strategy == STRATEGY_MEDIUM)
		apply_medium(&stacks, bench);
	else if (input->strategy == STRATEGY_COMPLEX)
		ft_printf("Applying Complex Algorithm\n");
	print_stack(stacks, 'a');
	print_stack(stacks, 'b');
	free(stacks.stack_a);
	free(stacks.stack_b);
}

static void	init_bench(t_bench *bench, t_input *input)
{
	float	disorder;

	disorder = compute_disorder(input->values, input->size);
	bench->disorder_max = disorder * 100;
	bench->disorder_min = ((int)(disorder * 10000)) % 100;
	ft_printf("Disorder: %d.%d%%\n", bench->disorder_max, bench->disorder_min);
	bench->strategy = input->strategy;
	bench->total_operations = 0;
	bench->count_sa = 0;
	bench->count_sb = 0;
	bench->count_ss = 0;
	bench->count_pa = 0;
	bench->count_pb = 0;
	bench->count_ra = 0;
	bench->count_rb = 0;
	bench->count_rr = 0;
	bench->count_rra = 0;
	bench->count_rrb = 0;
	bench->count_rrr = 0;
}

// Still lacks printing directly to STDERR and add Equivalent THEORETICAL COMPLEXITY CLASS
// √
static void	print_bench(t_bench *bench)
{
	ft_printf("[bench] disorder:  %d.%d%%\n", bench->disorder_max, bench->disorder_min);
	ft_printf("[bench] strategy: %s / ", strategy_to_str(bench->strategy));
	ft_printf("HERE GOES THE EQUIVALENT THEORETICAL COMPLEXITY CLASS\n");
	ft_printf("[bench] total_ops:  %d\n", bench->total_operations);
	ft_printf("[bench] sa:  %d  ", bench->count_sa);
	ft_printf("sb:  %d  ", bench->count_sb);
	ft_printf("ss:  %d  ", bench->count_ss);
	ft_printf("pa:  %d  ", bench->count_pa);
	ft_printf("pb:  %d\n", bench->count_pb);
	ft_printf("[bench] ra:  %d  ", bench->count_ra);
	ft_printf("rb:  %d  ", bench->count_rb);
	ft_printf("rr:  %d  ", bench->count_rr);
	ft_printf("rra:  %d  ", bench->count_rra);
	ft_printf("rrb:  %d  ", bench->count_rrb);
	ft_printf("rrr:  %d  \n", bench->count_rrr);
}
