/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:33:50 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/23 12:48:27 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("=== INICIANDO TESTES DO MEMMOVE ===\n\n");

	// -------------------------------------------------------------
	// TESTE 1: Cópia Padrão (Sem sobreposição)
	// -------------------------------------------------------------
	char src1[] = "Abacate";
	char dest1_original[10] = {0};
	char dest1_sua[10] = {0};

	memmove(dest1_original, src1, 5);
	ft_memmove(dest1_sua, src1, 5);

	printf("[TESTE 1] Cópia simples (5 bytes):\n");
	printf("  Original: %s\n", dest1_original);
	printf("  Sua Lib : %s\n", dest1_sua);
	if (strcmp(dest1_original, dest1_sua) == 0)
		printf("  -> OK! ✅\n\n");
	else
		printf("  -> FALHOU! ❌\n\n");

	// -------------------------------------------------------------
	// TESTE 2: Overlap - Destino DEPOIS da Origem (dest > src)
	// Esse é o caso do "de trás para frente" que quebra o memcpy!
	// -------------------------------------------------------------
	char array2_orig[] = "123456789";
	char array2_sua[]  = "123456789";

	// Mover os 5 primeiros bytes ("12345") duas casas para a direita
	memmove(array2_orig + 2, array2_orig, 5);
	ft_memmove(array2_sua + 2, array2_sua, 5);

	printf("[TESTE 2] Overlap (Destino > Origem):\n");
	printf("  Original: %s\n", array2_orig);
	printf("  Sua Lib : %s\n", array2_sua);
	if (strcmp(array2_orig, array2_sua) == 0)
		printf("  -> OK! ✅\n\n");
	else
		printf("  -> FALHOU! ❌\n\n");

	// -------------------------------------------------------------
	// TESTE 3: Overlap - Destino ANTES da Origem (dest < src)
	// -------------------------------------------------------------
	char array3_orig[] = "abcdefghi";
	char array3_sua[]  = "abcdefghi";

	// Mover 5 bytes a partir da posição 2 ("cdefg") duas casas para a esquerda
	memmove(array3_orig, array3_orig + 2, 5);
	ft_memmove(array3_sua, array3_sua + 2, 5);

	printf("[TESTE 3] Overlap (Destino < Origem):\n");
	printf("  Original: %s\n", array3_orig);
	printf("  Sua Lib : %s\n", array3_sua);
	if (strcmp(array3_orig, array3_sua) == 0)
		printf("  -> OK! ✅\n\n");
	else
		printf("  -> FALHOU! ❌\n\n");

	// -------------------------------------------------------------
	// TESTE 4: Caso Extremo - NULL com tamanho 0
	// Se o seu código não tiver a proteção inicial, ele vai dar SegFault aqui.
	// -------------------------------------------------------------
	printf("[TESTE 4] Caso limite (NULL, NULL, 0):\n");
	
	void *res_orig = memmove(NULL, NULL, 0);
	void *res_sua  = ft_memmove(NULL, NULL, 0);
	
	if (res_orig == res_sua)
		printf("  -> Ambos retornaram NULL sem travar! OK! ✅\n\n");
	else
		printf("  -> Retornos divergentes! FALHOU! ❌\n\n");

	char str[] = "abcdef";
	char *arrayt = ft_memmove(str + 2, str, 4);

	printf("%s", str);
	printf("=== FIM DOS TESTES ===\n");
	return (0);
}*/
