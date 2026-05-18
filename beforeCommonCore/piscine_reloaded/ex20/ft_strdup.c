/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:44:22 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/12 16:08:42 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (*src++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	cpy = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	i = 0;
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
