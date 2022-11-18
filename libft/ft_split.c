/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:39:26 by lperroti          #+#    #+#             */
/*   Updated: 2022/11/14 20:34:36 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	strscount(const char *str, char charset)
{
	size_t	nb;

	nb = 0;
	while (*str)
	{
		while (*str == charset)
			str++;
		if (*str)
			nb++;
		while (*str != charset && *str)
			str++;
	}
	return (nb);
}

static size_t	wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

void	freetab(char **tab, size_t size)
{
	while (size)
		free(tab[size--]);
	free(tab);
}

char	*getfirstword(const char *s, char c)
{
	char	*word;
	int		i;

	word = malloc((wordlen(s, c) + 1) * sizeof(char));
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tabindex;

	tab = malloc((strscount(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tabindex = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			tab[tabindex] = getfirstword(s, c);
			if (!tab[tabindex])
			{
				freetab(tab, tabindex);
				return (NULL);
			}
			tabindex++;
			s += wordlen(s, c);
		}
	}
	tab[tabindex] = NULL;
	return (tab);
}
