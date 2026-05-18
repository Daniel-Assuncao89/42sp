/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:38:28 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/26 14:27:23 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	root;

	root = 1;
	if (nb < 0)
		return (0);
	while (root <= (nb / root))
	{
		if ((root * root) == nb)
			return (root);
		root++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
    int tests[] = {0, 1, 2, 3, 4, 9, 10, 15, 16, 25, -4, 2147395600};
    int i = 0;

    while (i < 12)
    {
        printf("sqrt(%d) = %d\n", tests[i], ft_sqrt(tests[i]));
        i++;
    }
    return (0);
}
*/
