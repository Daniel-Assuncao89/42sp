/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:32:51 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/27 17:17:30 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	if (ft_is_prime(nb))
		next_prime = nb;
	else if (nb < 2)
		next_prime = 2;
	else
	{
		next_prime = 0;
		nb++;
		while (ft_is_prime(nb) == 0)
			nb++;
		next_prime = nb;
	}
	return (next_prime);
}
/*
#include <stdio.h>

int ft_find_next_prime(int nb);

int main(void)
{
    int tests[] = {
        -10, -1, 0, 1, 2, 3, 4, 6, 8, 10,
        11, 12, 13, 14, 15, 16,  17, 18, 
		19, 20, 24, 25, 26,
        97, 100, 1000,
        2147483640
    };

    int i = 0;
    int size = sizeof(tests) / sizeof(tests[0]);

    while (i < size)
    {
        printf("next_prime(%d) = %d\n", tests[i], ft_find_next_prime(tests[i]));
        i++;
    }
    return (0);
}
*/
