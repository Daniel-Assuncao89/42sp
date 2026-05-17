/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:36:42 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/16 20:36:44 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** SUA FUNÇÃO
*/
void	ft_foreach(int *tab, int length, void (*f)(int));

/*
** FUNÇÕES DE TESTE
*/
void	print_number(int n)
{
	printf("%d ", n);
}

void	print_double(int n)
{
	printf("%d ", n * 2);
}

void	print_is_even(int n)
{
	if (n % 2 == 0)
		printf("EVEN ");
	else
		printf("ODD ");
}

void	print_ascii(int n)
{
	printf("%c ", n);
}

/*
** MAIN DE TESTES
*/
int	main(void)
{
	int	arr1[] = {1, 2, 3, 4, 5};

	int	arr2[] = {42};

	int	arr3[] = {-5, 0, 10, -42};

	int	arr4[] = {65, 66, 67, 68};

	printf("=== TESTE 1: print_number ===\n");
	ft_foreach(arr1, 5, print_number);
	printf("\n\n");

	printf("=== TESTE 2: print_double ===\n");
	ft_foreach(arr1, 5, print_double);
	printf("\n\n");

	printf("=== TESTE 3: print_is_even ===\n");
	ft_foreach(arr1, 5, print_is_even);
	printf("\n\n");

	printf("=== TESTE 4: apenas 1 elemento ===\n");
	ft_foreach(arr2, 1, print_number);
	printf("\n\n");

	printf("=== TESTE 5: negativos ===\n");
	ft_foreach(arr3, 4, print_number);
	printf("\n\n");

	printf("=== TESTE 6: ASCII ===\n");
	ft_foreach(arr4, 4, print_ascii);
	printf("\n\n");

	printf("=== TESTE 7: length = 0 ===\n");
	ft_foreach(arr1, 0, print_number);
	printf("\n");
}
