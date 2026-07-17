/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:13:43 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/17 12:13:46 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

/**
 * Valida se o usuario já passou alguma estrategia, se sim retorna 0.
 * Seta a estrategia escolhida pelo usuario na struct t_input.
 */
static int	set_strategy(t_input *input, t_strategy strategy)
{
	if (input->has_strategy)
		return (0);
	input->strategy = strategy;
	input->has_strategy = 1;
	return (1);
}

/**
 * Valida se a flag é valida, se não for retorna 0.
 * Se for valida, seta a estrategia escolhida pelo usuario na struct t_input.
 */
int	parse_flag(char *str, t_input *input)
{
	if (ft_strncmp(str, "--bench", 99) == 0)
	{
		if (input->bench)
			return (0);
		input->bench = 1;
		return (1);
	}
	if (ft_strncmp(str, "--simple", 99) == 0)
		return (set_strategy(input, STRATEGY_SIMPLE));
	if (ft_strncmp(str, "--medium", 99) == 0)
		return (set_strategy(input, STRATEGY_MEDIUM));
	if (ft_strncmp(str, "--complex", 99) == 0)
		return (set_strategy(input, STRATEGY_COMPLEX));
	if (ft_strncmp(str, "--adaptive", 99) == 0)
		return (set_strategy(input, STRATEGY_ADAPTIVE));
	return (0);
}
