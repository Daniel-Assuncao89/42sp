/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:36:22 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/22 17:28:21 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_alphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (ft_alphanum(str[i]) && (i == 0 || !ft_alphanum(str[i - 1])))
		{
			if (ft_lowercase(str[i]))
				str[i] -= 32;
		}
		else
		{
			if (ft_uppercase(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char array[] = "aMaNha+oUtRo dia";
	char array2[] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("%s\n", ft_strcapitalize(array));
	printf("%s\n", ft_strcapitalize(array2));
}*/
