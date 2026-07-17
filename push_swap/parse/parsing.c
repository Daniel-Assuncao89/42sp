/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:09:33 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/17 12:11:19 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/**
 * Inicializa a struct t_input com valores default.
 * values = NULL, size = 0, strategy = STRATEGY_ADAPTIVE, has_strategy = 0, bench = 0
 * Retorna void.
 */
void	init_input(t_input *input)
{
	input->values = NULL;
	input->size = 0;
	input->strategy = STRATEGY_ADAPTIVE;
	input->has_strategy = 0;
	input->bench = 0;
}

/**
 * Faz a primeira leitura dos argumentos, conta quantos numeros existem para alocar o array de inteiros.
 * Faz a segunda leitura dos argumentos, salva os numeros no array de inteiros.
 * Retorna 1 se tudo ok, 0 se algum erro.
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

/**
 * Printa todas as informações do input de maneira bem formatada
 */
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

/**
 * Convert enum t_strategy para str ao mesmo tempo que valida
 * se é uma estratégia válida
 */
char	*strategy_to_str(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("--simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("--medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("--complex");
	if (strategy == STRATEGY_ADAPTIVE)
		return ("--adaptive");
	return ("unknown");
}
