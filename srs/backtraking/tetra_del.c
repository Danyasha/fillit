/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:40:37 by btorp             #+#    #+#             */
/*   Updated: 2019/02/13 22:02:23 by btorp            ###   ########.fr       */
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

void	tetra_del(t_map *map, t_dlst *tet)
{
	int		i;
	int		k;
	char	c;

	k = 0;
	c = find_letter(tet);
	while (map->map[k])
	{
		i = 0;
		while (map->map[k][i])
		{
			if (map->map[k][i] == c)
				map->map[k][i] = '.';
			i++;
		}
		k++;
	}
}