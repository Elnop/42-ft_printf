/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:52:26 by leon              #+#    #+#             */
/*   Updated: 2022/11/14 23:59:13 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	prev = NULL;
	while (*lst)
	{
		prev = *lst;
		lst = &(*lst)->next;
	}
	if (prev)
		prev->next = new;
	*lst = new;
}
