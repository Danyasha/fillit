/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:52 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 10:42:50 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlst			*ft_dlst_find(t_dlst *elem, int priority)
{
	t_dlst	*temp;

	temp = elem;
	while (temp->next != NULL && temp->priority != priority)
		temp = temp->next;
	if (temp->priority == priority)
		return (temp);
	else
		return (NULL);
}
