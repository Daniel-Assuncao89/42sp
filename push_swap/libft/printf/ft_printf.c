/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:12:57 by hequeiro          #+#    #+#             */
/*   Updated: 2026/06/12 15:12:59 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_switch(const char *format, int *counter, va_list arg_list)
{
	int	x;

	if (*(format + 1) == 'c')
		handle_c(arg_list, counter);
	else if (*(format + 1) == 's')
		handle_s(arg_list, counter);
	else if (*(format + 1) == 'p')
		handle_p(arg_list, counter);
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		handle_d(arg_list, counter);
	else if (*(format + 1) == 'u')
		handle_u(arg_list, counter);
	else if (*(format + 1) == 'x' || *(format + 1) == 'X')
	{
		x = to_hex(va_arg(arg_list, unsigned int), *(format + 1));
		*counter += x;
	}
	else if (*(format + 1) == '%')
		handle_percent(counter);
}

static void	handle_args(const char *format, int *counter, va_list arg_list)
{
	while (*format)
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		else
		{
			my_switch(format, counter, arg_list);
			*counter -= 2;
			format++;
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		counter;

	counter = ft_strlen(format);
	va_start(arg_list, format);
	handle_args(format, &counter, arg_list);
	va_end(arg_list);
	return (counter);
}
