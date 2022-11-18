/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:51:18 by leon              #+#    #+#             */
/*   Updated: 2022/11/18 21:57:13 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

static void	printarg(const char **str, va_list args)
{
	if (**str == '%')
		write(1, "%", 1);
	if (**str == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1);
	if (**str == 'd' || **str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (**str == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	if (**str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (**str == 'x')
		ft_putnbr_base((size_t)va_arg(args, void *), "0123456789abcdef");
	if (**str == 'X')
		ft_putnbr_base((size_t)va_arg(args, void *), "0123456789ABCDEF");
	if (**str == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base((size_t)va_arg(args, void *), "0123456789abcdef");
	}
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	size_t	i;

	va_start(args, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		if (i)
		{
			write(1, str, i);
			str += i;
		}
		if (*str == '%')
		{
			str++;
			printarg(&str, args);
			str++;
		}
	}
	return (0);
}
int main()
{
	ft_printf("------>%c\n", '2');
	return 0;
}
