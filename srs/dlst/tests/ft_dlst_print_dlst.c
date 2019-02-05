/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_print_dlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:56 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 08:40:54 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dlst.h"

void			ft_dlst_print_dlst(t_dlst *head)
{
	char	*s;

	s = head->tetra[0];
	while(head)
	{
		printf("Height = %i\n, wight = %i\n, priority = %i\n, tetra:\n", head->height, head->width, head->priority);
		for (int i = 0; s[i]; i++)
			printf("%s\n", s[i]);
		head = head->next;
	}
}