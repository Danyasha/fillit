/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:37:29 by btorp             #+#    #+#             */
/*   Updated: 2019/02/11 19:33:01 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../validate.h"
#include <fcntl.h>


void			ft_dlst_print_dlst(t_dlst *head)
{
	char	*s;

	printf("printing list:\n");
	if (head == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while(head)
	{
		s = head->tetra[0];
		printf("--------------------------\nHeight = %i\nwight = %i\npriority = %i\ntetra:\n", head->height, head->width, head->priority);
		for (int i = 1; s; i++)
		{
			printf("%s\n", s);
			s = head->tetra[i];
		}
		head = head->next;
	}
}

int		main(void)
{
	int		fd;
	t_dlst	*head;

	fd = open("test.fillit", O_RDONLY);
	head = ft_validate_main(fd);
	if (head)
	{
		printf("valid\n");
		ft_dlst_print_dlst(head);
		ft_dlst_del_all(&head);
	}
	else
	{
		printf("invalid\n");
	}
	close(fd);
	return (0);
}
