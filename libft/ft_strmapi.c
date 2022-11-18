/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:40 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/16 03:14:53 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	cpy = ft_strdup(s);
	if (!cpy)
		return (cpy);
	i = 0;
	while (cpy[i])
	{
		cpy[i] = f(i, cpy[i]);
		i++;
	}
	return (cpy);
}
