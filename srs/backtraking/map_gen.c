/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:40:13 by btorp             #+#    #+#             */
/*   Updated: 2019/02/14 21:44:37 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

static	int		find_count(t_dlst *t)
{
	if (t == NULL)
		return (0);
	while (t->next != NULL)
		t = t->next;
	return (t->priority + 1);
}

static	int		find_size_of_side(int s)
{
	int	n;

	n = 1;
	while (n * n < s)
		n++;
	return (n);
}

t_map			*map_gen(t_dlst *t, int size)
{
	t_map	*map;
	int		i;
	int		k;

	if (size == 0)
		i = find_size_of_side(find_count(t) * 4);
	else
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
