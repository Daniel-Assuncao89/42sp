/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:50:52 by hequeiro          #+#    #+#             */
/*   Updated: 2026/06/12 15:50:55 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_c(va_list arg_list, int *counter)
{
	ft_putchar_fd(va_arg(arg_list, int), 1);
	*counter += 1;
}

void	handle_percent(int *counter)
{
	ft_putchar_fd('%', 1);
	*counter += 1;
}
