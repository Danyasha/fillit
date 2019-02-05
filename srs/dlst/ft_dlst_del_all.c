/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:49 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 08:35:31 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

static	t_dlst	*del_elem(t_dlst **elem)
{
	t_dlst	*temp;
	t_dlst	*temp_next;

	temp = *elem;
	temp_next = temp->next;
	free(temp->tetra);
	temp->prev = NULL;
	free(temp);
	return (temp_next);
}

void			ft_dlst_del_all(t_dls **head)
{
	t_dlst	*temp;

	temp = *head;
	while(temp->next)
	{
		temp = del_elem(&temp);
	}
	temp = del_elem(&temp);
}