/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:09:38 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/12 15:02:58 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	i = 0;
	char *t = "literal pointer";

	i = printf("%%teste teste teste\n");
	printf("OG: %d\n", i);
	i = ft_printf("%%teste teste teste\n");
	printf("FT: %d\n", i);
	printf("----------\n");
	i = printf("%c\n", 'z');
	printf("OG: %d\n", i);
	i = ft_printf("%c\n", 'z');
	printf("FT: %d\n", i);
	printf("----------\n");
	i = printf("%s\n", "teste teste teste");
	printf("OG: %d\n", i);
	i = ft_printf("%s\n", "teste teste teste");
	printf("FT: %d\n", i);
	printf("----------\n");
	i = printf("%d\n", 12345);
	printf("OG: %d\n", i);
	i = ft_printf("%d\n", 12345);
	printf("FT: %d\n", i);
	printf("----------\n");
    i = printf("%i\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%i\n", 35);
	printf("FT: %d\n", i);
    printf("----------\n");
    i = printf("%x\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%x\n", 35);
	printf("FT: %d\n", i);
    printf("----------\n");
    i = printf("%X\n", 35);
    printf("OG: %d\n", i);
    i = ft_printf("%X\n", 35);
	printf("FT: %d\n", i);
    printf("----------\n");
    i = printf("%u\n", -26);
    printf("OG: %d\n", i);
    i = ft_printf("%u\n", -26);
	printf("FT: %d\n", i);
    printf("----------\n");
    i = printf("%p\n", t);
    printf("OG: %d\n", i);
    i = ft_printf("%p\n", t);
	printf("FT: %d\n", i);
    printf("----------\n");
	ft_printf("%d, %s, %x, %p texto\n", 32, "lorem", 26, t);
	i = ft_printf("%s\n", NULL);
	//printf("texto % outro");
	ft_printf("Hello %a world");
}
