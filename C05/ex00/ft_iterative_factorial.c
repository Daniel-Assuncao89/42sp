/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:50:08 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/25 11:47:09 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 0;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	result = nb;
	while (nb > 1)
	{
		result *= nb - 1;
		nb -= 1;
	}
	return (result);
}
