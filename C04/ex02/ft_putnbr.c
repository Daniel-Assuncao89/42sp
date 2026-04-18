/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:41:20 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/16 13:37:16 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	number[10];
	long	nbl;
	int		count;

	count = 0;
	nbl = nb;
	if (nbl < 0)
	{
		nbl *= -1;
		write(1, "-", 1);
	}
	while (nbl >= 10)
	{
		number[count] = (nbl % 10) + '0';
		nbl = nbl / 10;
		count++;
	}
	number[count] = nbl + '0';
	while (count >= 0)
	{
		write (1, &number[count], 1);
		count--;
	}
}
/*
int main(void)
{
	ft_putnbr(457);
	write (1, "\n", 1);
	ft_putnbr(2147483647);
	write (1, "\n", 1);
	ft_putnbr(-2147483648);
}
*/
