/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:26:10 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H

# define DLST_H
# include "../../libft/libft.h"

typedef	struct	s_dlst
{
	char			**tetra;
	int				height;
	int				width;
	int				priority;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

t_dlst			*ft_dlst_new(char **tetra, int priority, int height, int width);
t_dlst			*ft_dlst_add(t_dlst **head, t_dlst *new_elem);
t_dlst			*ft_dlst_find(t_dlst *elem, int priority);
void			ft_dlst_del_all(t_dlst **head);

#endif