/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:09:12 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/12 16:35:54 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	result = malloc ((max - min) * sizeof(int));
	i = 0;
	if (min >= max)
		result = NULL;
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}
