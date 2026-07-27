/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:25 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 16:14:52 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "parse.h"

typedef struct s_stack
{
	int		*stack;
	int		amount;
	char	name;
}	t_stack;

typedef struct s_stacks
{
	t_stack	s_a;
	t_stack	s_b;
	int		max_length;
}	t_stacks;

typedef struct s_bench
{
	int			disorder_min;
	int			disorder_max;
	t_strategy	strategy;
	int			total_operations;
	int			count_sa;
	int			count_sb;
	int			count_ss;
	int			count_pa;
	int			count_pb;
	int			count_ra;
	int			count_rb;
	int			count_rr;
	int			count_rra;
	int			count_rrb;
	int			count_rrr;
}	t_bench;

// For production
// Creates a t_stacks containing stack_a with all receiving numbers
// and stack_b of the same size but empty with zeros.
// t_stacks	init_stacks(int ac, char **av);
t_stacks	init_stacks(int values[], int length);
void		init_bench(t_bench *bench, t_input *input);
void		print_bench(t_bench *bench);

// For debug
void		print_stack(const t_stack *stack);
void		print_stacks(const t_stacks *stacks);

#endif // PUSH_SWAP_H
