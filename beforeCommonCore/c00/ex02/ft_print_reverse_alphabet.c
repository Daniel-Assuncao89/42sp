/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@stundent.42sp.org.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:40:15 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/02 11:47:49 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ascii;

	ascii = 122;
	while (ascii >= 97)
	{
		write(1, &ascii, 1);
		ascii--;
	}
}
