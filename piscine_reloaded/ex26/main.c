/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:54:45 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/16 20:54:50 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** SUA FUNÇÃO
*/
int	ft_count_if(char **tab, int (*f)(char *));

/*
** FUNÇÕES DE TESTE
*/

int	is_empty(char *str)
{
	return (str[0] == '\0');
}

int	has_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	is_42(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != "42"[i])
			return (0);
		i++;
	}
	if (i == 2)
		return (1);
	return (0);
}

int	starts_with_b(char *str)
{
	if (str[0] == 'b')
		return (1);
	return (0);
}

/*
** MAIN DE TESTES
*/

int	main(void)
{
	char	*tab1[] = {"abc", "", "42", "", 0};

	char	*tab2[] = {"banana", "abacaxi", "uva", "pera", 0};

	char	*tab3[] = {"42", "21", "42", "1337", 0};

	char	*tab4[] = {"bola", "casa", "barco", "teste", 0};

	char	*tab5[] = {"", "", "", 0};

	printf("=== TESTE 1: is_empty ===\n");
	printf("Resultado: %d\n\n", ft_count_if(tab1, is_empty));

	printf("=== TESTE 2: has_a ===\n");
	printf("Resultado: %d\n\n", ft_count_if(tab2, has_a));

	printf("=== TESTE 3: is_42 ===\n");
	printf("Resultado: %d\n\n", ft_count_if(tab3, is_42));

	printf("=== TESTE 4: starts_with_b ===\n");
	printf("Resultado: %d\n\n", ft_count_if(tab4, starts_with_b));

	printf("=== TESTE 5: todos vazios ===\n");
	printf("Resultado: %d\n\n", ft_count_if(tab5, is_empty));

	return (0);
}
