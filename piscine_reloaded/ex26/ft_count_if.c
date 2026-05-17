/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:39:31 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/16 20:59:43 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			result++;
		i++;
	}
	return (result);
}
