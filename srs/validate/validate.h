/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:13:47 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
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

int		ft_check_tetra(char **tetra);
t_dlst	*ft_validate_main(int fd);
int		ft_add_tetra(char **lines, t_dlst **list);

#endif