/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:25 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 01:37:47 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "parse.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	max_length;
	int	amount_a;
	int	amount_b;
}	t_stacks;

typedef struct s_bench
{
	int			disorder_min;		// DONE
	int			disorder_max;		// DONE
	t_strategy	strategy;			// DONE
	int			total_operations;	// DONE
	int			count_sa;			// DONE
	int			count_sb;			// DONE
	int			count_ss;			// DONE
	int			count_pa;			// DONE
	int			count_pb;			// DONE
	int			count_ra;			// DONE
	int			count_rb;			// DONE
	int			count_rr;			// DONE
	int			count_rra;			// DONE
	int			count_rrb;			// DONE
	int			count_rrr;			// DONE
}	t_bench;

// For production
// Creates a t_stacks containing stack_a with all receiving numbers
// and stack_b of the same size but empty with zeros.
// t_stacks	init_stacks(int ac, char **av);
t_stacks	init_stacks(int values[], int length);
int			is_ordered(int nbs[], int size);

// For debug
void		print_stack(t_stacks stacks, char c);

#endif // PUSH_SWAP_H
