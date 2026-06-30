/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:51:14 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/30 18:11:30 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int is_digit(int c)
{
    return ((c > '0' && c < '9'));
}
// Retorna 1 se a string for um número válido. Transforma o numero via ponteiro.
int ft_atoi_ps(const char *str, int *result)
{
	long long num;
	int       sign;
	int       i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    // 2. Se a string era SÓ o sinal ou vazia, é inválido (ex: "+" ou "")
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!is_digit(str[i]))
			return (0); // Encontrou letra, espaço extra ou lixo -> Erro!
		num = num * 10 + (str[i] - '0');
		if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
			return (0); // Passou dos limites -> Erro!
		i++;
	}
	*result = (int)(num * sign); // Número convertido por ponteiro
	return (1);
}
