/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:45:59 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/14 20:16:28 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	writenum(char *dest, long nb)
{
	if (nb > 9)
		writenum(dest - 1, nb / 10);
	*dest = nb % 10 + '0';
}

int	numlen(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len = 2;
		nb *= -1;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = (long)n;
	len = numlen(nb);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		writenum(str + len - 1, -nb);
	}
	else
		writenum(str + len - 1, nb);
	str[len] = 0;
	return (str);
}
