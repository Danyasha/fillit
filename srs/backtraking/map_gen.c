/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:40:13 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 15:54:43 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

t_map			*map_gen(int size)
{
	t_map	*map;
	int		i;
	int		k;

	i = size;
	k = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->map = (char**)(malloc(sizeof(char*) * (i + 1)));
	map->map[i] = NULL;
	while(k < i)
	{
		map->map[k] = ft_strnew(i);
		ft_memset(map->map[k], '.', i);
		k++;
	}
	map->n = i;
	return (map);
}
