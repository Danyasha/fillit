/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:21:42 by btorp             #+#    #+#             */
/*   Updated: 2019/02/14 22:04:19 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRAKING_H

# define BACKTRAKING_H
# include "../validate/validate.h"

typedef	struct	s_map
{
	char			**map;
	int				n;
}				t_map;

int		backtraking_main(t_dlst **head);
t_map	*find_sol(t_map map, t_dlst temp, int x, int y);
t_map	*map_gen(t_dlst *t, int size);
int		tetra_place(t_map *map, t_dlst *tet, int x, int y);
void	tetra_del(t_map *map, t_dlst *tet);
#endif