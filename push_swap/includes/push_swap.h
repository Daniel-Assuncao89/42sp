/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:25 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 19:09:08 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	max_length;
	int	amount_a;
	int	amount_b;
}	t_stacks;

// For production
// Creates a t_stacks containing stack_a with all receiving numbers
// and stack_b of the same size but empty with zeros.
// t_stacks	init_stacks(int ac, char **av);
t_stacks	init_stacks(int values[], int length);
int			is_ordered(int nbs[], int size);

// For debug
void		print_stack(t_stacks stacks, char c);

#endif // PUSH_SWAP_H
