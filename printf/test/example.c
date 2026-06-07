/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:09:38 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/07 17:19:18 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int	main(void)
{
	int	i = 0;
	char *t = "literal pointer";

	i = printf("%%teste teste teste\n");
	printf("OG: %d\n", i);
	i = ft_printf("%%teste teste teste");
	printf("\nFT: %d\n", i);
	printf("----------\n");
	i = printf("%c\n", 'z');
	printf("OG: %d\n", i);
	i = ft_printf("%c", 'z');
	printf("\nFT: %d\n", i);
	printf("----------\n");
	i = printf("%s\n", "teste teste teste");
	printf("OG: %d\n", i);
	i = ft_printf("%s", "teste teste teste");
	printf("\nFT: %d\n", i);
	printf("----------\n");
	i = printf("%d\n", 12345);
	printf("OG: %d\n", i);
	i = ft_printf("%d", 12345);
	printf("\nFT: %d\n", i);
	printf("----------\n");
    i = printf("%i\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%i", 35);
	printf("\nFT: %d\n", i);
    printf("----------\n");
    i = printf("%x\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%x", 35);
	printf("\nFT: %d\n", i);
    printf("----------\n");
    i = printf("%X\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%X", 35);
	printf("\nFT: %d\n", i);
    printf("----------\n");
    i = printf("%u\n", -26);
    printf("OG: %d\n", i);
    i = ft_printf("%u", -26);
	printf("\nFT: %d\n", i);
    printf("----------\n");
    i = printf("%p\n", t);
    printf("OG: %d\n", i);
    i = ft_printf("%p", t);
	printf("\nFT: %d\n", i);
    printf("----------\n");
}
