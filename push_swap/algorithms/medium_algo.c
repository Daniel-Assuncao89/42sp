/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 02:38:21 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/19 03:32:54 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This algo works by "pre-sorting" the numbers by sending
// them in chunks to stack B based on their values.
// So the first chunk that contains the lowest numbers are
// send to stack B first and pre-ordered there.
// The second chunk will keep the same logic and will naturally
// be at the top of the first chunk.
// When Stack A gets empty, push it all back to Stack A and
// doing a lot of less sorting than it would usually need to do
// with the simple algorithm.
// Medium:
// 1. Duplicate the stacks and ranking the values of each number: -- DONE
// 		For example: OG Stack:  [7, 15, -8, 13, 22, 0, 4]
// 					 Duplicate: [3,  5,  0,  4,  6, 1, 2]
// 2. Define chunk-size based on √n. Rounded down
// 3. Look closer number at the top of the stack that fits in the chunk
// 4. Move it to the top
// 5. Prepare Stack B
// 6. Push it to Stack B
// 7. Repeat 3-6 until chunk is done
// 8. Define chunk again
// 9. Repeat 3-8 until Stack A is empty
// 10.Push all numbers back and adjusting minimally to go back sorted
#include "algorithms.h"
#include "libft.h"
#include "push_swap.h"

int	next_minor(int *stack, int max_length, int current_minor);
int *create_duplicate(int *stack, int max_length);

void	apply_medium(t_stacks *stacks, t_bench *bench)
{
	int	*duplicate;

	ft_printf("Applying Medium Algorithm\n");
	duplicate = create_duplicate(stacks->stack_a, stacks->amount_a);
	free(duplicate);
	(void)bench;
}

int next_minor(int *stack, int max_length, int current_minor)
{
	int	minor;
	int	i;

	minor = 0;
	i = 0;
	while (i < max_length)
	{
		if (stack[i] > stack[current_minor] && stack[i] < stack[minor])
			minor = i;
		i++;
	}
	return (minor);

}

int *create_duplicate(int *stack, int max_length)
{
	int	*duplicate;
	int	i;
	int	j;
	int minor_index;

	duplicate = ft_calloc(max_length, sizeof(int));

	j = 0;
	minor_index = search_minor(stack, max_length);
	duplicate[minor_index] = j;
	while (++j < max_length)
	{
		minor_index = next_minor(stack, max_length, minor_index);
		duplicate[minor_index] = j;
	}
	i = 0;
	ft_printf("Duplicate: ");
	while (i < max_length)
	{
		ft_printf("%d ", duplicate[i]);
		i++;
	}
	ft_printf("\n");
	return (duplicate);
}
