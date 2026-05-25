/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:13:56 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/25 18:39:15 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1. Conta quantas palavras separadas por 'c' existem na string
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// 2. Se malloc de alguma palavra falhar, limpa tudo o que já foi alocado
static char	**free_matrix(char **matrix, size_t i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
	return (NULL);
}

// 3. A função principal que divide a string
char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	matrix = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			matrix[i++] = ft_substr(s, 0, len);
			if (!matrix[i - 1])
				return (free_matrix(matrix, i - 1));
			s += len;
		}
	}
	matrix[i] = NULL;
	return (matrix);
}
