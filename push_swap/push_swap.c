/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:09:19 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 17:15:06 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithms.h"
#include "parse.h"

// Needs to implement Complex Algo
// Needs to --bench correctly to stderr and show algo complexity -- DONE

/*********************************
 * CHECAR COMENTÁRIOS EM PARSE.H *
 *********************************/

/*********************************
 ***** REMOVER ALGO_UTILS2.C *****
 *********************************/

static void		strategy_checker(t_input *input, t_bench *bench);

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
		init_bench(&bench, &input);
		if (!(bench.disorder_max == 0 && bench.disorder_min == 0))
			strategy_checker(&input, &bench);
		if (input.bench)
			print_bench(&bench);
		free_input(&input);
	}
	return (0);
}

static void	strategy_checker(t_input *input, t_bench *bench)
{
	t_stacks	stacks;

	stacks = init_stacks(input->values, input->size);
	if (input->strategy == STRATEGY_ADAPTIVE)
	{
		if (bench->disorder_max < 20)
			apply_simple(&stacks, bench);
		else if (bench->disorder_max >= 20 && bench->disorder_max < 50)
			apply_medium(&stacks, bench);
		else if (bench->disorder_max >= 50)
			apply_complex(&stacks, bench);
	}
	else if (input->strategy == STRATEGY_SIMPLE)
		apply_simple(&stacks, bench);
	else if (input->strategy == STRATEGY_MEDIUM)
		apply_medium(&stacks, bench);
	else if (input->strategy == STRATEGY_COMPLEX)
		apply_complex(&stacks, bench);
	free(stacks.s_a.stack);
	free(stacks.s_b.stack);
}
