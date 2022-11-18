/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:31:01 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/16 18:47:57 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	size_t	i;

	if (*s == (unsigned char)c)
		return ((char *)s);
	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
