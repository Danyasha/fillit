/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:27:53 by btorp             #+#    #+#             */
/*   Updated: 2019/02/06 15:10:19 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static	t_tet	*find_x_and_y(char **lines)
{
	int		i;
	int		k;
	int		g;
	t_tet	*tet;

	tet = (t_tet*)malloc(sizeof(t_tet));
	i = k = g = 0;
	while(i <= 3)
	{
		k = 0;
		while (k <= 3)
		{
			if (lines[i][k] == '#')
			{
				if (g == 0)
				{
					tet->x1f = k;
					tet->y1f = i;
				}
				if (g == 2)
				{
					tet->x1l = k;
					tet->y1l = i;
				}
				g++;
			}
			k++;
		}
		i++;
	}
	i = k = g = 0;
	while(k <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			if (lines[i][k] == '#')
			{
				if (g == 0)
				{
					tet->x2f = k;
					tet->y2f = i;
				}
				if (g == 2)
				{
					tet->x2l = k;
					tet->y2l = i;
				}
				g++;
			}
			i++;
		}
		k++;
	}
	return (tet);
}

static	char	get_tet(t_tet **tet, char **lines)
{
	char	**block;
	int		xtopleft;
	int		ytopleft;
	int		xdownright;
	int		ydownright;


}

int				ft_add_tetra(char **lines, t_dlst **list)
{
	t_tet	*tet;
	char	**block;

	tet = find_x_and_y(lines);
	block = gen_tet(&tet, lines);

}