/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:42:05 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/19 05:55:00 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	write_and_count(long long int nbr, char *base, unsigned int baselen,
	ssize_t *pwritecount)
{
	if (nbr / baselen > 0)
		write_and_count(nbr / baselen, base, baselen, pwritecount);
	*pwritecount += write(1, &base[nbr % baselen], 1);
}

int	checkbase(char *base)
{
	int		i;

	if (!base[1] || !base[0])
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

ssize_t	ft_putnbr_base(long long int nbr, char *base)
{
	unsigned int	baselen;
	ssize_t			writecount;

	if (!checkbase(base))
		return (0);
	baselen = ft_strlen(base);
	writecount = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		writecount += write(1, "-", 1);
	}
	write_and_count(nbr, base, baselen, &writecount);
	return (writecount);
}
