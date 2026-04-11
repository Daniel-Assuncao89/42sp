/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:46:09 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/11 15:51:22 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			i++;
			continue ;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("Only uppercase: %d\n", ft_str_is_uppercase("AJIOWOUIO"));
	printf("Uppercase and lowercase: %d\n", ft_str_is_uppercase("AJIOWOUIOads"));
	printf("Empty string: %d\n", ft_str_is_uppercase(""));
}
*/
