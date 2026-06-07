/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 13:51:37 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/07 17:24:39 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printchar(int c);
int	ft_printstr(const char *s);
int	ft_printhex(int c, unsigned int nbr);
int	ft_printunsigned(unsigned int nbr);
int	ft_printptr(int *ptr);
int	ft_printnbr(int nbr);
int	ft_printf(const char *format, ...);

#endif
