/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:20:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/18 12:00:55 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_matchf(int c, va_list args)
{
	int			printed_chars;

	printed_chars = 0;
	if (c == 'c')
		printed_chars += ft_printchar(va_arg(args, int));
	else if (c == 's')
		printed_chars += ft_printstr(va_arg(args, const char *));
	else if (c == 'p')
		printed_chars += ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		printed_chars += ft_printnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		printed_chars += ft_printhex(c, va_arg(args, unsigned int));
	else if (c == 'u')
		printed_chars += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	index;
	int				chars;

	if (!format)
		return (-1);
	va_start(args, format);
	index = 0;
	chars = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			chars += ft_matchf(format[index + 1], args);
			index++;
		}
		else
			chars += ft_printchar(format[index]);
		index++;
	}
	va_end(args);
	return (chars);
}
