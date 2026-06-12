/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:40:07 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/11 19:38:33 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	line_len(char *line_str, int buff_size)
{
	int	len;

	len = 0;
	while (s[len] != '\n')
	{
		if (len > buff_size)
			break;
		len++;
	}
	return (len);
}

int	verify_line(char *str, int size)
{
	if (!str)
		return (NULL);
	return (1);
}
