/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:49 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

static	t_dlst	*del_elem(t_dlst **elem)
{
	t_dlst	*temp;
	t_dlst	*temp_next;
	int		i;

	i = 0;
	temp = *elem;
	temp_next = temp->next;
	while(temp->tetra[i])
	{
		free(temp->tetra[i]);
		temp->tetra[i] = NULL;
		i++;
	}
	free(temp->tetra);
	temp->tetra = NULL;
	temp->next = NULL;
	temp->prev = NULL;
	if (temp->next)
		temp_next->prev = NULL;
	free(*elem);
	*elem = NULL;
	return (temp_next);
}

void			ft_dlst_del_all(t_dlst **head)
{
	t_dlst	*temp;
	temp = *head;
	while(temp)
	{
		temp = del_elem(&temp);
	}
	*head = NULL; //тут какой-то костыль, head должен быть null в цикле выше
}
