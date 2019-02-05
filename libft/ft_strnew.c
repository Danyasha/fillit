/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:43:13 by btorp             #+#    #+#             */
/*   Updated: 2019/01/27 21:16:21 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	shit;

	if (size == 4294967295)
		shit = 0;
	else
		shit = 1;
	a = (char*)malloc(size + shit);
	if (a == NULL)
	{
		return (NULL);
	}
	ft_bzero(a, size + shit);
	return (a);
}
