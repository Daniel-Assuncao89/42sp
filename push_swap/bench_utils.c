/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:01:28 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 19:01:29 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static float	compute_disorder(const int *stack, int max_length);
static void		print_err(const char *str, int x);
static void		print_strategy(t_bench *bench);

void	init_bench(t_bench *bench, t_input *input)
{
	float	disorder;

	disorder = compute_disorder(input->values, input->size);
	bench->disorder_max = disorder * 100;
	bench->disorder_min = ((int)(disorder * 10000)) % 100;
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

static float	compute_disorder(const int *stack, int max_length)
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
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	print_bench(t_bench *bench)
{
	print_err("[bench] disorder:  ", bench->disorder_max);
	print_err(".", bench->disorder_min);
	ft_putstr_fd("%\n", 2);
	print_strategy(bench);
	print_err("[bench] total_ops:  ", bench->total_operations);
	ft_putstr_fd("\n", 2);
	print_err("[bench] sa:  ", bench->count_sa);
	print_err("  sb:  ", bench->count_sb);
	print_err("  ss:  ", bench->count_ss);
	print_err("  pa:  ", bench->count_pa);
	print_err("  pb:  ", bench->count_pb);
	ft_putstr_fd("\n", 2);
	print_err("[bench] ra:  ", bench->count_ra);
	print_err("  rb:  ", bench->count_rb);
	print_err("  rr:  ", bench->count_rr);
	print_err("  rra:  ", bench->count_rra);
	print_err("  rrb:  ", bench->count_rrb);
	print_err("  rrr:  ", bench->count_rrr);
	ft_putstr_fd("\n", 2);
}

static void	print_err(const char *str, int x)
{
	char	*num;
	char	*final;

	num = ft_itoa(x);
	final = ft_strjoin(str, num);
	ft_putstr_fd(final, 2);
	free(num);
	free(final);
}

static void	print_strategy(t_bench *bench)
{
	char	*strategy;

	strategy = strategy_to_str(bench->strategy);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd(" / ", 2);
	if (bench->disorder_max < 20)
		ft_putendl_fd("O(n²)", 2);
	else if (bench->disorder_max >= 20 && bench->disorder_max < 50)
		ft_putendl_fd("O(n√n)", 2);
	else if (bench->disorder_max >= 50)
		ft_putendl_fd("O(n log n)", 2);
}
