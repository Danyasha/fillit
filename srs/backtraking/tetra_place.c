/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:28:42 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 17:13:39 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

static	char	find_letter(t_dlst *tet)
{
	int	i;
	int	k;

	k = 0;
	while (k <= tet->height)
	{
		i = 0;
		while (i <= tet->width)
		{
			if (tet->tetra[k][i] != '.')
				return (tet->tetra[k][i]);
			i++;
		}
		k++;
	}
	return ('0');
}

static	int		clean_map(t_map *map, t_dlst *tet, int x, int y)
{
	int		i;
	int		k;
	char	c;

	k = 0;
	c = find_letter(tet);
	while (k < tet->height && map->map[k + y])
	{
		i = 0;
		while (i < tet->width && map->map[k][i])
		{
			if (map->map[k + y][i + x] == c)
				map->map[k + y][i + x] = '.';
			i++;
		}
		k++;
	}
	return (0);
}

int				tetra_place(t_map *map, t_dlst *tet, int x, int y)
{
	int	i;
	int	k;

	k = 0;
	while (k < tet->height)
	{
		if (!(map->map[k + y]))
			return (clean_map(map, tet, x, y));
		i = 0;
		while (i < tet->width && i < map->n)
		{
			if (map->map[k + y][i + x] == '.')
				map->map[k + y][i + x] = tet->tetra[k][i];
			else if(tet->tetra[k][i] == '.')
				;
			else
				return (clean_map(map, tet, x, y));
			i++;
		}
		k++;
	}
	return (1);
}
