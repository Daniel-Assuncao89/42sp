/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:18:25 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/25 16:38:07 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
//Sequência de Fibonacci =(1, 1, 2, 3, 5, 8, 13, 21, 34, 55, …)
#include<stdio.h>
int main (void)
{
	printf("%d", ft_fibonacci(10));
}
*/
