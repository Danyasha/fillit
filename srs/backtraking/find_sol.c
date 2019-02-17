/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:24:12 by btorp             #+#    #+#             */
/*   Updated: 2019/02/17 14:29:16 by btorp            ###   ########.fr       */
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
	write(1, "ERR\n", 4);
	return ('0');
}

static	void	clean_board(t_map *map, t_dlst *temp, int x, int y)
{
	char	c;
	int		x2;
	int		y2;

	y2 = 0;
	c = find_letter(temp);
	while (y + y2 < map->n && y2 < temp->height)
	{
		x2 = 0;
		while (x + x2 < map->n && x2 < temp->width)
		{
			if (map->map[y + y2][x + x2] == c)
				map->map[y + y2][x + x2] = '.';
			x2++;
		}
		y2++;
	}
}

static	int		findx(t_map *map, int *i, int *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->n)
	{
		x = 0;
		while (x < map->n)
		{
			if (map->map[y][x] == '.')
			{
				*i = x;
				*g = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

// static	int		findy(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < map->n)
// 	{
// 		x = 0;
// 		while (x < map->n)
// 		{
// 			if (map->map[y][x] == '.')
// 				return (y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (-1);
// }

t_map			*find_sol(t_map *map, t_dlst *temp, int x, int y)
{
	int		i;
	int		g;
	t_map	*t;
	
	g = 0;
	if (tetra_place(map, temp, x, y))
	{
		if (temp->next == NULL)
			return (map);
		if(!findx(map, &i, &g))
			return (NULL);
		// if (i == -1)
		// 	return (NULL);
		// g = findy(map);
		t = find_sol(map, temp->next, i, g);
		if (t)
			return(t);
	}
	clean_board(map, temp, x, y);
	if (x == map->n - 1 && !(x == map->n - 1 && y == map->n - 1))
		return (find_sol(map, temp, 0, y + 1));
	else if (!(x == map->n - 1 && y == map->n - 1))
		return (find_sol(map, temp, x + 1, y));
	if (x == map->n - 1 && y == map->n - 1)
		return (NULL);
	return (map);
}