/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:18:59 by btorp             #+#    #+#             */
/*   Updated: 2019/02/06 11:48:18 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checkpoint(char **tetra, int x, int y)
{
	int	i;

	i = 0;
	if (x - 1 > 0 && y - 1 > 0)
	{
		if (tetra[y - 1][x - 1] == '#')
			i++;
	}
	if (x - 1 > 0 && y + 1 > 3)
	{
		if (tetra[y + 1][x - 1] == '#')
			i++;
	}
	if (x + 1 > 3 && y - 1 > 0)
	{
		if (tetra[y - 1][x + 1] == '#')
			i++;
	}
	if (x + 1 > 3 && y + 1 > 3)
	{
		if (tetra[y + 1][x + 1] == '#')
			i++;
	}
	return (i);
}

int		ft_check_tetra(char **tetra)
{
	int	count;
	int	connections;
	int	x;
	int	y;

	y = 0;
	count = 0;
	connections = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			if (tetra[y][x] == '#')
			{
				count++;
				connections += checkpoint(tetra, x, y);
			}
			x++;
		}
		y++;
	}
	if (count == 4 && (connections == 6 || connections == 8))
		return (1);
	return (0);
}