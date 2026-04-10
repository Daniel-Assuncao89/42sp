/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:27:41 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/09 13:11:04 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		valor_a;
	int		valor_b;

	valor_a = *a;
	valor_b = *b;
	*a = valor_a / valor_b;
	*b = valor_a % valor_b;
}
/*
#include <stdio.h>
int	main(void)
{
	int		a;
	int		b;
	int*	ptr_a;
	int*	ptr_b;

	a = 7;
	b = 3;
	ptr_a = &a;
	ptr_b = &b;
	ft_ultimate_div_mod(ptr_a, ptr_b);
	printf("Resultado: %d\n", a);
	printf("Resto: %d\n", b);
}
*/
