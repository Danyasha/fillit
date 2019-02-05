/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:40:29 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 00:15:17 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf, const void *buf2, size_t count)
{
	unsigned char	*big;
	unsigned char	*little;

	big = (unsigned char*)buf;
	little = (unsigned char*)buf2;
	if (count == 0)
		return (0);
	if (*big && *little && !count)
		return (0);
	while (count--)
	{
		if (*big != *little)
			return (*big - *little);
		little++;
		big++;
	}
	return (0);
}
