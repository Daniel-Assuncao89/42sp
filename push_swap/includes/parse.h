/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:02:19 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 19:16:28 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
// # include <stdlib.h>
// # include <unistd.h>
// # include <stdio.h> //Adicionado para teste, remover dps

// # define PS_INT_MAX 2147483647 //Verificar se está dentro da norma isso e se realmente precisa definir esses valores aqui.
// # define PS_INT_MIN -2147483648

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

// Struct que vai guardar tudo que foi obtido na entrada do usuario.
typedef struct s_input
{
	int			*values; //Vai ser o array de inteiros validados.
	int			size; //Qtd de numero
	t_strategy	strategy; //Qual algoritmo usar
	int			has_strategy; //Validar se o usuario já passou alguma estrategia. Evita o envio de duas flags com estrategia.
	int			bench; //Validar se o modo bench foi passado.
}	t_input;

int		parse_input(int argc, char **argv, t_input *input);
int		count_input(int argc, char **argv, t_input *input);
int		fill_input(int argc, char **argv, t_input *input);
int		ft_atoi_ps(char *str, int *result);
int		is_flag(char *str);
int		parse_flag(char *str, t_input *input);
void	init_input(t_input *input);
void	free_input(t_input *input);
void	free_split(char **split);
void	print_input(t_input *input);
char	*strategy_to_str(t_strategy strategy);

#endif
