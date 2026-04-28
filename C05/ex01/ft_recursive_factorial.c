/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:48:24 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/25 12:24:14 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}
/*
#include <stdio.h>
int main (void)
{
	printf("%d", ft_recursive_factorial(5));
}
*/
