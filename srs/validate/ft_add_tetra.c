/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:27:53 by btorp             #+#    #+#             */
/*   Updated: 2019/02/06 14:45:33 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	ft_add_tetra(char **lines, t_dlst **list)
{
	int		i;
	int		k;
	int		g;
	t_tet	tet;
 
	i = k = g = 0;
	while(i <= 3)
	{
		k = 0;
		while (k <= 3)
		{
			if (lines[i][k] == '#')

			k++;
		}
		i++;
	}
	i = g = 0;
	while(i <= 3)
	{
		k = 0;
		while (k <= 3)
		{
			if (lines[i][k] == '#')
				y = i;
			k++;
		}
		i++;
	}
	return 1;
}