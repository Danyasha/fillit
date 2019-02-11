/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:13:47 by btorp             #+#    #+#             */
/*   Updated: 2019/02/11 15:03:47 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H

# define VALIDATE_H

# include "../dlst/dlst.h"
# include "../../libft/libft.h"

typedef	struct	s_tet
{
	int	x1f;
	int	x1l;
	int	y1f;
	int	y1l;
	int	x2f;
	int	x2l;
	int	y2f;
	int	y2l;
}				t_tet;

typedef	struct	s_coords
{
	int	xtopl;
	int	ytopl;
	int	xdownr;
	int	ydownr;
}				t_coords;


int		ft_check_tetra(char **tetra);
t_dlst	*ft_validate_main(int fd);
int		ft_add_tetra(char ***lines, t_dlst **list);
void	ft_place_ints(int *d1, int *d2, int s1, int s2);

#endif