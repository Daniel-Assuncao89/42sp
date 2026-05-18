/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:18:42 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/06 18:09:40 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_separator(char c, char *charset)
{
	while(*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(*str++)
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_separator(str, charset))
			str++;
		if (*str && !is_separator(str, charset))
		{
			words++;
			while (*str && !is_separator(str, charset))
				str++;
		}
	}
	return (words);
}
	
char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		size;

	size = count_words(str, charset);
	split = (char **) malloc((size + 1)*sizeof(char))
	if (!split)
		return (NULL);
	while (*str)
	{
		**split = ft_strcmp(str, charset);
		str++;
		split++;
	}
	return (split);
}

#include <stdio.h>
int	main(void)
{
	char	**split;

	split = ft_split("quero-outro", "-");
	printf("%s", split[0]);
}
