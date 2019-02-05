/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dls_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:45 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 08:12:44 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlst			*ft_dlst_add(t_dlst **head, t_dlst *new_elem)
{
	t_dlst	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_elem;
	new_elem->prev = temp;
	return (new_elem);
}