/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:54 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 08:08:14 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlst		*ft_dlst_new(char **tetra, int priority, int height, int width)
{
	t_dlst	*a;

	if (!(a = (t_dlst*)malloc(sizeof(t_dlst))))
		return (NULL);
	a->tetra = tetra;
	a->priority = priority;
	a->height = height;
	a->width = width;
	a->next = NULL;
	a->prev = NULL;
	return (a);
}