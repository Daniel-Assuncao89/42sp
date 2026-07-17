/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:14:15 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/17 12:14:19 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
/*
 * Faz a primeira leitura dos argumentos, não salva os numeros.
 * Quebra os argumentos com ft_split.
 * Valida se é flag ou numero.
 * Se for flag, valida se é uma flag valida e seta a estrategia ou bench.
 * Conta quantos numeros existem para alocar o array de inteiros.
 * Retorna 1 se tudo ok, 0 se algum erro.
 */

/**
 * Valida se o token é uma flag, se for chama parse_flag.
 * Se não for flag, valida se é um numero valido com ft_atoi_ps.
 */
static int	count_token(char *token, t_input *input)
{
	int	tmp;

	if (is_flag(token))
		return (parse_flag(token, input));
	if (!ft_atoi_ps(token, &tmp))
		return (0);
	input->size++;
	return (1);
}

/*
 * Valida se o split não está vazio, se estiver retorna 0.
 * Itera sobre o split, para cada token chama count_token.
 */
static int	count_split(char **split, t_input *input)
{
	int	i;

	i = 0;
	if (!split[0])
		return (0);
	while (split[i])
	{
		if (!count_token(split[i], input))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Itera sobre os argumentos, para cada argumento chama ft_split.
 * Para cada split chama count_split.
 */
int	count_input(int argc, char **argv, t_input *input)
{
	char	**split;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!count_split(split, input))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (input->size > 0);
}
