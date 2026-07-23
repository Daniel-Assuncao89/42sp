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
// 			     	 Duplicate: [3,  5,  0,  4,  6, 1, 2]
// 2. Define chunk-size based on √n. Rounded down -- DONE
// 3. Look closer number at the top of the stack that fits in the chunk -- DONE
// 4. Move it to the top -- DONE
// 5. Push it to Stack B -- DONE
// 6. Adjust last inserted number in Stack B -- DONE
// 7. Repeat 3-6 until chunk is done -- DONE
// 8. Define chunk again -- DONE
// 9. Repeat 3-8 until Stack A is empty -- DONE
// 10.Push all numbers back and adjusting minimally to go back sorted -- DONE

// Clean up Duplicate operation prints
// Norminette

#include "algorithms.h"
#include "libft.h"
#include "push_swap.h"
#include "operations.h"

int			next_minor(const int *stack, int max_length, int current_minor);
t_stacks	create_duplicate(int *stack, int max_length);
int			square_root(int nb);
int			closer_element(int *stack, int max_length, int lower_bound, int upper_bound);
int			search_value(int *stack, int max_length, int value);

void	apply_medium(t_stacks *stacks, t_bench *bench)
{
	t_stacks	duplicate;
	int			chunk_size;
	int			lower_bound;
	int			upper_bound;
	int			element_index;
	int			i;
	int			moved_from_chunk;
	int			major;

	ft_printf("\033[1;33m" "Applying Medium Algorithm\n");
	duplicate = create_duplicate(stacks->stack_a, stacks->amount_a);
	i = 0;

	chunk_size = square_root(stacks->amount_a);
	ft_printf("Chunk-size: %d\n", chunk_size);

	ft_printf("Dupli A:");
	while (i < stacks->amount_a)
		ft_printf("  %d", duplicate.stack_a[i++]);
	ft_printf("\n");

	lower_bound = 0;
	upper_bound = chunk_size - 1;
	ft_printf("First Lower Bound: %d\n", lower_bound);
	ft_printf("First Upper Bound: %d\n", upper_bound);

	while (stacks->amount_a > 0)
	{
		moved_from_chunk = 0;
		while (moved_from_chunk <= (upper_bound - lower_bound))
		{
			ft_printf("Moved from chunk: %d\n", moved_from_chunk);

			element_index = closer_element(duplicate.stack_a, duplicate.amount_a, lower_bound, upper_bound);
			move_to_top(element_index, stacks->stack_a, stacks->amount_a, bench);
			move_to_top(element_index, duplicate.stack_a, duplicate.amount_a, bench);

			pb(&duplicate, bench);
			pb(stacks, bench);

			if (duplicate.stack_b[duplicate.amount_b - 1] < (lower_bound + (chunk_size / 2)))
			{
				rb(duplicate.stack_b, duplicate.amount_b, bench);
				rb(stacks->stack_b, stacks->amount_b, bench);
			}
			moved_from_chunk++;
		}
		lower_bound += chunk_size;
		upper_bound += chunk_size;
		if (duplicate.amount_a < chunk_size)
			upper_bound = (lower_bound + (duplicate.amount_a - 1));
		ft_printf("Next Lower Bound: %d\n", lower_bound);
		ft_printf("Next Upper Bound: %d\n", upper_bound);
	}
	
	major = (duplicate.amount_b - 1);
	while (major >= 0)
	{
		move_to_top(search_value(duplicate.stack_b, duplicate.amount_b, major), stacks->stack_b, stacks->amount_b, bench);
		move_to_top(search_value(duplicate.stack_b, duplicate.amount_b, major), duplicate.stack_b, duplicate.amount_b, bench);
		pa(&duplicate, bench);
		pa(stacks, bench);
		major--;
	}
	
	ft_printf("========= DUPLICATE =========\n");
	print_stack(duplicate, 'a');
	print_stack(duplicate, 'b');

	ft_printf("\n========= ORIGINALS =========\n");
	print_stack(*stacks, 'a');
	print_stack(*stacks, 'b');

	free(duplicate.stack_a);
	free(duplicate.stack_b);
	(void)bench;

	ft_printf("\033[0m");
}

int next_minor(const int *stack, int max_length, int current_minor)
{
	int	minor_index;
	int	higher_index;
	int	i;

	higher_index = 0;
	i = 0;
	while (i++ < max_length)
		if (stack[i - 1] >= stack[higher_index])
			higher_index = (i - 1);
	minor_index = higher_index;
	i = 0;
	while (i++ < max_length)
		if (stack[i - 1] > stack[current_minor] && stack[i - 1] < stack[minor_index])
			minor_index = (i - 1);
	return (minor_index);
}

t_stacks	create_duplicate(int *stack, int max_length)
{
	t_stacks	duplicate;
	int	j;
	int minor_index;

	duplicate.stack_a = ft_calloc(max_length, sizeof(int));
	duplicate.amount_a = max_length;
	duplicate.stack_b = ft_calloc(max_length, sizeof(int));
	duplicate.amount_b = 0;
	j = 0;
	minor_index = search_minor(stack, max_length);
	duplicate.stack_a[minor_index] = j;
	while (++j < max_length)
	{
		minor_index = next_minor(stack, max_length, minor_index);
		duplicate.stack_a[minor_index] = j;
	}
	return (duplicate);
}

int	square_root(int nb)
{
	int	i;

	i = 1;
	while ((i * i) <= nb && (i * i) <= 46341)
		i++;
	return (i - 1);
}

int	closer_element(int *stack, int max_length, int lower_bound, int upper_bound)
{
	int	i; // Downwards
	int	j; // Upwards

	i = (max_length - 1);
	if (stack[i] >= lower_bound && stack[i] <= upper_bound)
	// {
	// 	ft_printf("Closer is at the top with value %d\n", stack[i]);
		return (i);
	// }
	i--;
	j = 0;
	while (j <= i)
	{
		if (stack[i] >= lower_bound && stack[i] <= upper_bound)
		// {
		// 	ft_printf("Closer downward is %d of index %d\n", stack[i], i);
			return (i);
		// }
		else if (stack[j] >= lower_bound && stack[j] <= upper_bound)
		// {
		// 	ft_printf("Closer upward is %d of index %d\n", stack[j], j);
			return (j);
		// }
		i--;
		j++;
	}
	return (-1);
}

int	search_value(int *stack, int max_length, int value)
{
	int	i;

	i = 0;
	while (i < max_length)
		if (stack[i++] == value)
			return (i - 1);
	return (0);
}
