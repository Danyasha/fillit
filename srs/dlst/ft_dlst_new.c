/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:54 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:38:09 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"
#include <string.h>

static	char	**copy(char **s, int width, int height)
{
	char	**temp;
	int		i;

	temp = (char**)malloc(sizeof(char*) * (height + 1));
	temp[height] = NULL;
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strnew(width);
		ft_memcpy(temp[i], s[i], width);
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (temp);
}


t_dlst			*ft_dlst_new(char **tetra, int priority, int height, int width)
{
	t_dlst	*a;

	if (!(a = (t_dlst*)malloc(sizeof(t_dlst))))
		return (NULL);
	a->tetra = copy(tetra, width, height);
	a->priority = priority;
	a->height = height;
	a->width = width;
	a->next = NULL;
	a->prev = NULL;
	return (a);
}
