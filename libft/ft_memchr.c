/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:40:36 by btorp             #+#    #+#             */
/*   Updated: 2018/12/11 00:58:26 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (((char*)memptr)[i] == (char)val)
			return ((void*)&memptr[i]);
		i++;
	}
	return (NULL);
}
