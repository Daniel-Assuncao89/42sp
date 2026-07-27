/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:09:33 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/23 17:02:04 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// Initializes t_input with default values.
void	init_input(t_input *input)
{
	input->values = NULL;
	input->size = 0;
	input->strategy = STRATEGY_ADAPTIVE;
	input->has_strategy = 0;
	input->bench = 0;
}

/**
 * Does the first read of arguments, counts how many numbers exist
 * to alloc the array of ints.
 * Then does the second read of arguments, saves the numbers in the
 * previous created array.
 * Returns 1 if all is ok, 0 if any error occurred;
 */
int	parse_input(int argc, char **argv, t_input *input)
{
	int	total;

	init_input(input);
	if (!count_input(argc, argv, input))
		return (0);
	total = input->size;
	input->values = malloc(sizeof(int) * total);
	if (!input->values)
		return (0);
	input->size = 0;
	if (!fill_input(argc, argv, input))
		return (0);
	return (1);
}

// Prints t_input info in a clean, formatted layout
void	print_input(t_input *input)
{
	int	i;

	ft_printf("=== PARSING RESULT ===\n");
	ft_printf("strategy: %s\n", strategy_to_str(input->strategy));
	ft_printf("has_strategy: %d\n", input->has_strategy);
	ft_printf("bench: %d\n", input->bench);
	ft_printf("size: %d\n", input->size);
	i = 0;
	while (i < input->size)
	{
		ft_printf("values[%d]: %d\n", i, input->values[i]);
		i++;
	}
	ft_printf("======================\n");
}

// Converts t_strategy to string at the same time that checks
// if the given strategy is valid
char	*strategy_to_str(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("Simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("Medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("Complex");
	if (strategy == STRATEGY_ADAPTIVE)
		return ("Adaptive");
	return ("unknown");
}
