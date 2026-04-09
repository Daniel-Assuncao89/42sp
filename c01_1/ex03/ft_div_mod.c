/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 17:13:15 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/07 18:12:00 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int		resultado_divisao;
	int		resto_divisao;
	int* 	ptr_divisao;
	int*	ptr_resto;

	resultado_divisao = 0;
	ptr_divisao = &resultado_divisao;
	resto_divisao = 0;
	ptr_resto = &resto_divisao;
	printf("Resultado: %d\n", resultado_divisao);
	printf("Resto: %d\n", resto_divisao);
	ft_div_mod(7, 2, ptr_divisao, ptr_resto);
	printf("Resultado: %d\n", resultado_divisao);
	printf("Resto: %d\n", resto_divisao);
}*/
