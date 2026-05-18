/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:06:30 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/27 15:29:33 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int ft_is_prime(int nb);

int main(void)
{
    int tests[] = {
        -10, -1, 0, 1,
        2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        25, 49, 97, 100, 101, 2147483647
    };
    int i = 0;
    int size = sizeof(tests) / sizeof(tests[0]);

    while (i < size)
    {
        printf("ft_is_prime(%d) = %d\n", tests[i], ft_is_prime(tests[i]));
        i++;
    }
    return (0);
}
*/
