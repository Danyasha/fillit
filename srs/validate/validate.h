/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:13:47 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 12:36:50 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H

# define VALIDATE_H

# include "../dlst/dlst.h"
# include "../../libft/libft.h"
int		ft_check_tetra(char **tetra);
t_dlst	*ft_validate_main(int fd);
int		ft_add_tetra(char **lines, t_dlst **list);

#endif