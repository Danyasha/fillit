/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_print_dlst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:02:56 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 10:04:57 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst_test.h"

void			ft_dlst_print_dlst(t_dlst *head)
{
	char	*s;

	if (head == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while(head)
	{
		s = head->tetra[0];
		printf("Height = %i\nwight = %i\npriority = %i\ntetra:\n", head->height, head->width, head->priority);
		for (int i = 1; s; i++)
		{
			printf("%s\n", s);
			s = head->tetra[i];
		}
		head = head->next;
	}
}