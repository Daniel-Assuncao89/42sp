/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:30:24 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/18 13:48:14 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	result = 1;
	while (nb > 1)
	{
		if (nb > 2147483647)
			return (0);
		result *= nb;
		nb--;
	}
	return (result);
}
