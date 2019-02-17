/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:24:11 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 17:55:44 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

static	void	map_del(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->n)
	{
		free((*map)->map[i]);
		(*map)->map[i] = NULL;
		i++;
	}
	free((*map)->map);
	(*map)->map = NULL;
	free(*map);
	*map = NULL;
}

static	int		find_size_of_side(int s)
{
	int	n;

	n = 1;
	while (n * n < s)
		n++;
	return (n);
}

static	int		find_count(t_dlst *t)
{
	if (t == NULL)
		return (0);
	while (t->next != NULL)
		t = t->next;
	return (find_size_of_side((t->priority + 1) * 4));
}

void	map_write(t_map	**map)
{
	int	i;

	i = 0;
	while (i < (*map)->n)
	{
		ft_putstr((*map)->map[i]);
		write(1, "\n", 1);
		i++;
	}
	//map_del(map);
}

int		backtraking_main(t_dlst **head)
{
	t_map	*map;
	int		size;

	size = find_count(*head);
	map = map_gen(size);
	while(!find_sol(map, *head, 0, 0))
	{
		map_del(&map);
		map = map_gen(size++);
	}
	map_write(&map);
	return (0);
}