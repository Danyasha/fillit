/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:19:27 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 01:19:06 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		isinv2(char *s1, char *s2)
{
	int i;
	int len;
	int len2;

	len = 0;
	len2 = 0;
	i = 0;
	while (s2[len] != '\0')
		len++;
	while (s1[len2] != '\0')
		len2++;
	if (len2 < len)
		return (0);
	while (i < len && i < len2)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int len;

	i = 0;
	if (!*s1 && !*s2)
		return ((char*)s1);
	len = ft_strlen((char*)s2);
	while (s1[i] != '\0')
	{
		if (isinv2((char*)&s1[i], (char*)s2))
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
