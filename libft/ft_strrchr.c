/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:34:16 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/16 18:54:23 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	long	i;

	i = 0;
	if (!*s && !c)
		return ((char *)s);
	if (!*s)
		return (NULL);
	while (s[i])
		i++;
	while (i > -1 && s[i] != (unsigned char)c)
		i--;
	if (i == -1)
		return (NULL);
	return ((char *)s + i);
}
