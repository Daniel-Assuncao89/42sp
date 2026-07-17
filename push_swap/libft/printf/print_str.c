/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:16:47 by hequeiro          #+#    #+#             */
/*   Updated: 2026/06/12 16:16:50 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_s(va_list arg_list, int *counter)
{
	char	*temp;

	temp = va_arg(arg_list, char *);
	if (!temp)
	{
		ft_putstr_fd("(null)", 1);
		*counter += 6;
	}
	else
	{
		ft_putstr_fd(temp, 1);
		*counter += ft_strlen(temp);
	}
}
