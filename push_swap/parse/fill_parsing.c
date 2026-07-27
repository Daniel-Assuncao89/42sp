/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:13:18 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/17 12:13:32 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
/**
 * Faz a segunda leitura dos argumentos, salva os numeros no array de inteiros.
 * Aqui não precisa validar se é flag ou numero,
 * pois isso já foi feito na primeira leitura.
 * Valida se o numero já existe no array, se existir retorna 0.
 * preenche o array de inteiros com os numeros validados.
 */

static int	has_duplicate(t_input *input, int value)
{
	int	i;

	i = 0;
	while (i < input->size)
	{
		if (input->values[i] == value)
			return (1);
		i++;
	}
	return (0);
}

/**
 * Valida se o numero já existe no array, se existir retorna 0.
 * preenche o array de inteiros com os numeros validados.
 */
static int	add_value(t_input *input, int value)
{
	if (has_duplicate(input, value))
		return (0);
	input->values[input->size] = value;
	input->size++;
	return (1);
}

/**
 * Valida se o token é uma flag, se for retorna 1.
 * Se não for flag, valida se é um numero valido com ft_atoi_ps.
 * Se for numero valido, adiciona no array de inteiros.
 */
static int	fill_token(char *token, t_input *input)
{
	int	value;

	if (is_flag(token))
		return (1);
	if (!ft_atoi_ps(token, &value))
		return (0);
	return (add_value(input, value));
}

/**
 * Valida se o split não está vazio, se estiver retorna 0.
 * Itera sobre o split, para cada token chama fill_token.
 * fill_token valida se o token é flag ou numero, se for flag ignora,
 * se for numero valida e adiciona no array de inteiros.
 * ft_split quebra os argumentos em tokens, separados por espaço.
 */
static int	fill_split(char **split, t_input *input)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!fill_token(split[i], input))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Itera sobre os argumentos, para cada argumento chama ft_split.
 * Para cada split chama fill_split.
 * fill_split valida se o token é flag ou numero, se for flag ignora,
 * se for numero valida e adiciona no array de inteiros.
 * ft_split quebra os argumentos em tokens, separados por espaço.
 * Retorna 1 se tudo ok, 0 se algum erro.
 */
int	fill_input(int argc, char **argv, t_input *input)
{
	char	**split;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!fill_split(split, input))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}
