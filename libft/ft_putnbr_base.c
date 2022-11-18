/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:42:05 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/18 07:02:23 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

void	ft_putnbr_base(long int nbr, char *base)
{
	unsigned int	baselen;

	if (!checkbase(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	baselen = ft_strlen(base);
	if (nbr / baselen > 0)
		ft_putnbr_base(nbr / baselen, base);
	write(1, &base[nbr % baselen], 1);
}