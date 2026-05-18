/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:55:55 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/07 18:12:18 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		swap;

	swap = *b;
	*b = *a;
	*a = swap;
}
/*
#include <stdio.h>
int	main(void)
{
	int		num_a;
	int		num_b;
	int*	ptr_num_a;
	int*	ptr_num_b;

	num_a = 4;
	num_b = 6;
	printf("Valor original de a: %d\n", num_a);
	printf("Valor original de b: %d\n", num_b);

	ptr_num_a = &num_a;
	ptr_num_b = &num_b;
	ft_swap(ptr_num_a, ptr_num_b);
	printf("Valor trocado de a: %d\n", num_a);
	printf("Valor trocado de b: %d\n", num_b);
}*/
