/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:27:53 by btorp             #+#    #+#             */
/*   Updated: 2019/02/11 21:44:37 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static	void	find_firsts(char **lines, t_tet *a)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (lines[y][x] == '#')
			{
				if (i == 0)
					ft_place_ints(&(a->x1f), &(a->y1f), x, y);
				if (i == 3)
					ft_place_ints(&(a->x1l), &(a->y1l), x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

static	void	find_seconds(char **lines, t_tet *a)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (lines[y][x] == '#')
			{
				if (i == 0)
					ft_place_ints(&(a->x2f), &(a->y2f), x, y);
				if (i == 3)
					ft_place_ints(&(a->x2l), &(a->y2l), x, y);
				i++;
			}
			y++;
		}
		x++;
	}
}

static	void	tet_to_coords(t_tet **t, t_coords *coords)
{
	t_tet	*tet;

	tet = *t;
	if (tet->x1f == tet->x2f && tet->y1f == tet->y2f)
	{
		coords->xtopl = tet->x1f;
		coords->ytopl = tet->y1f;
	}
	else
	{
		coords->xtopl = tet->x2f;
		coords->ytopl = tet->y1f;
	}
	if (tet->x1l == tet->x2l && tet->y1l == tet->y2l)
	{
		coords->xdownr = tet->x2l;
		coords->ydownr = tet->y2l;
	}
	else
	{
		coords->xdownr = tet->x2l;
		coords->ydownr = tet->y1l;
	}
	free(*t);
	*t = NULL;
}

static	t_dlst	*gen_tet(char **lines, t_coords **c, int prior)
{
	char	**tetra;
	int		x;
	int		y;

	tetra = (char**)malloc(sizeof(char*) * ((*c)->ydownr - (*c)->ytopl + 2));
	tetra[(*c)->ydownr - (*c)->ytopl + 1] = NULL;
	y = 0;
	x = 0;
	while (y < (*c)->ydownr - (*c)->ytopl + 1)
	{
		x = 0;
		tetra[y] = ft_strnew((size_t)(*c)->xdownr - (*c)->xtopl + 1);
		while (x < (*c)->xdownr - (*c)->xtopl + 1)//запись строки в новую строку и потом генерация
		{
			tetra[y][x] = lines[(*c)->ytopl + y][(*c)->xtopl + x];
			x++;
		}
		y++;
	}
	return(ft_dlst_new(tetra, prior, (*c)->ydownr - (*c)->ytopl + 1, (*c)->xdownr - (*c)->xtopl + 1));
}

int				ft_add_tetra(char ***lines, t_dlst **list)
{
	t_tet		*tet;
	t_coords	*coords;
	static	int	i;
	t_dlst		*temp;

	tet = (t_tet*)malloc(sizeof(t_tet));
	coords = (t_coords*)malloc(sizeof(t_coords));
	find_firsts(*lines, tet);
	find_seconds(*lines, tet);
	tet_to_coords(&tet, coords);

	temp = gen_tet(*lines, &coords, i);
	ft_dlst_add(list, temp);
	free(coords);
	coords = NULL;
	free(tet);
	tet = NULL;
	i++;
	return (i);
}
