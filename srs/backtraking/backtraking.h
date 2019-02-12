/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtraking.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:21:42 by btorp             #+#    #+#             */
/*   Updated: 2019/02/12 22:02:54 by btorp            ###   ########.fr       */
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
#endif