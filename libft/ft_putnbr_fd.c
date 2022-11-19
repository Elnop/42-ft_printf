/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:34:19 by leon              #+#    #+#             */
/*   Updated: 2022/11/19 07:09:54 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static void	write_and_count(long int n, int fd, ssize_t *pcount)
{
	if (n > 9)
		write_and_count(n / 10, fd, pcount);
	n = n % 10 + '0';
	*pcount += write(fd, &n, 1);
}

ssize_t	ft_putnbr_fd(long long int n, int fd)
{
	ssize_t	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += write(fd, "-", 1);
	}
	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	write_and_count(n, fd, &count);
	return (count);
}
