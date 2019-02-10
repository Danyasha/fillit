/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:27:53 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:03:05 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"


int				ft_add_tetra(char **lines, t_dlst **list)
{
	t_tet	*tet;
	char	**block;

	tet = find_x_and_y(lines);
	block = gen_tet(&tet, lines);

}
