/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:36:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/09 13:22:38 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		c_inicial;
	int		c_final;
	int		int_rev;

	c_inicial = 0;
	c_final = size - 1;
	while (c_inicial < (size / 2))
	{
		int_rev = tab[c_final];
		tab[c_final] = tab[c_inicial];
		tab[c_inicial] = int_rev;
		c_inicial++;
		c_final--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int size;
	int i;
	int tab[] = {0, 1, 2, 3, 4, 5, 6};

	size = 7;
	i = 0;
	ft_rev_int_tab(tab, size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/
