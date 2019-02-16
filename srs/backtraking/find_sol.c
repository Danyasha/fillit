/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:24:12 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 17:08:04 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

t_map	*find_sol(t_map *map, t_dlst *temp, int x, int y)
{
	if (tetra_place(map, temp, x, y))
	{
		if (temp->next == NULL)
			return (map);
		return (find_sol(map, temp->next, 0, 0));
	}
	if (x == map->n - 1 && y == map->n - 1)
		return (NULL);
	else if (x == map->n - 1)
		return (find_sol(map, temp, 0, y + 1));
	else
		return (find_sol(map, temp, x + 1, y));
	return (map);
}