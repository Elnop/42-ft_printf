/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:45:15 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/16 21:27:02 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little || little == big)
		return ((char *)big);
	while (len > 0 && *big)
	{
		i = 0;
		while (i < len && little[i] == big[i] && big[i])
			i++;
		if (!little[i])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
