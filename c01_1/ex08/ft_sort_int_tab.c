/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:25:31 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/08 18:38:21 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	count_int;
	int	num_swap;

	count = 0;
	while (count < size)
	{
		count_int = count + 1;
		num_swap = tab[count];
		while (count_int < size)
		{
			if (num_swap > tab[count_int])
			{
				tab[count] = tab[count_int];
				tab[count_int] = num_swap;
				num_swap = tab[count];
			}
			count_int++;
		}
		count++;
	}
}
/*
#include <stdio.h>
int main(void)
{
	int tab[] = {6, 5, 4, 2, 3, 1};
	int size = 6;
	int i;

	i = 0;
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/
