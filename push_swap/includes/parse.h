/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:02:19 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/23 17:20:48 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "limits.h" // For INT_MIN and INT_MAX

/*******************************************************
 * LEMBRAR DE USAR INT_MIN E INT_MAX EM ATOI_PARSING.C *
 *******************************************************/

/******************************************************
 * TRADUZIR OU REMOVER COMENTÁRIOS EM COUNT_PARSING.H *
 ******************************************************/

/*****************************************************
 * TRADUZIR OU REMOVER COMENTÁRIOS EM FILL_PARSING.H *
 *****************************************************/

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_input
{
	int			*values;
	int			size;
	t_strategy	strategy;
	int			has_strategy;
	int			bench;
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
