/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:42:29 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 00:18:52 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	char	*sc1;
	char	*sc2;

	sc1 = (char*)s1;
	sc2 = (char*)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(sc1) + ft_strlen(sc2));
	if (newstr == NULL)
		return (NULL);
	ft_strcat(newstr, sc1);
	ft_strcat(newstr, sc2);
	return (newstr);
}
