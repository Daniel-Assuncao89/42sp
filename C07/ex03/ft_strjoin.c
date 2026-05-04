/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:49:36 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/29 18:16:28 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strsizelen(int size, char **strs, char *sep)
{
	int	strslen;
	int	i;

	strslen = 0;
	i = 0;
	while (i < size)
	{
		strslen += ft_strlen(strs[i]);
		i++;
	}
	strslen += ((size - 1) * ft_strlen(sep)) + 1;
	return (strslen);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	count_dest;
	int	count_src;

	count_dest = 0;
	count_src = 0;
	while (dest[count_dest])
		count_dest++;
	while (src[count_src])
	{
		dest[count_dest] = src[count_src];
		count_dest++;
		count_src++;
	}
	dest[count_dest] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		size_strs;
	char	*join;

	i = 0;
	size_strs = 0;
	if (size == 0)
	{
		join = malloc(1);
		join[0] = '\0';
		return (join);
	}
	size_strs = ft_strsizelen(size, strs, sep);
	join = (char *) malloc(size_strs * sizeof(char));
	join[0] = '\0';
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < (size - 1))
			ft_strcat(join, sep);
		i++;
	}
	return (join);
}
/*
#include <stdio.h>
int	main(void)
{
	char *arr[] = {"abc", "123", "Yuri"};

	printf("%s", ft_strjoin(3, arr, "-"));
}
*/
