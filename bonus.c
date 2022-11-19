/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 07:31:25 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/19 07:37:31 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static ssize_t	tagprocess_u(long int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (ft_putnbr_fd(nbr, 1));
}

static ssize_t	tagprocess_s(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (ft_putstr_fd(s, 1));
}

static ssize_t	tagprocess_p(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	if ((long long int)ptr == LONG_MIN)
		return (2 + write(1, "8000000000000000", 16));
	if ((long unsigned int)ptr == ULONG_MAX)
		return (2 + write(1, "ffffffffffffffff", 16));
	return (2 + ft_putnbr_base((long long int)ptr, HEX));
}

static ssize_t	printarg(const char **str, va_list args)
{
	if (**str == '%')
		return (write(1, "%", 1));
	if (**str == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	if (**str == 'd' || **str == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (**str == 'u')
		return (tagprocess_u(va_arg(args, unsigned int)));
	if (**str == 's')
		return (tagprocess_s(va_arg(args, char *)));
	if (**str == 'x')
		return (ft_putnbr_base((size_t)va_arg(args, unsigned int), HEX));
	if (**str == 'X')
		return (ft_putnbr_base((size_t)va_arg(args, unsigned int), BHEX));
	if (**str == 'p')
		return (tagprocess_p(va_arg(args, void *)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		charcount;

	charcount = 0;
	va_start(args, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		if (i)
		{
			write(1, str, i);
			charcount += i;
			str += i;
		}
		if (*str == '%')
		{
			str++;
			charcount += printarg(&str, args);
			str++;
		}
	}
	return (charcount);
}