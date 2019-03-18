/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:28:42 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 20:15:46 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				tetra_place(t_map *map, t_dlst *tet, int x, int y)
{
	int	i;
	int	k;

	k = 0;
	while (k < tet->height)
	{
		if (!(map->map[k + y]))
			return (0);
		i = 0;
		while (i < tet->width)
		{
			if (i + x == map->n)
				return (0);
			if (tet->tetra[k][i] == '.')
				;
			else if (map->map[k + y][i + x] == '.')
				map->map[k + y][i + x] = tet->tetra[k][i];
			else
				return (0);
			i++;
		}
		k++;
	}
	return (1);
}
