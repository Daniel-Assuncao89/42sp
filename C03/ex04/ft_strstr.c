/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:38:19 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/14 17:45:01 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;

	count = 0;
	while(to_find[count])
	{
		
	}
	return (str);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%s", strstr("ola, oi voce", "oi"));
}
