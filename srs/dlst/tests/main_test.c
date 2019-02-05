/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <btorp@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 08:41:52 by btorp             #+#    #+#             */
/*   Updated: 2019/02/05 10:04:10 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst_test.h"

static	char	**generator(int height, int width)
{
	char	**temp;

	temp = (char**)malloc(sizeof(char*) * height + 1);
	temp[height] = NULL;
	for (int k = 0; k < height; k++)
	{
		temp[k] = ft_strnew(width);
		temp[k] = ft_memset(temp[k], '.', width);
	}
	return (temp);
}

int		main(void)
{
	t_dlst	*temp;
	int		i;
	t_dlst	*head;
	int		h;
	int		w;

	h = 4;
	w = 4;
	i = 1;
	head = ft_dlst_new(generator(4, 4), i, h, w);
	while (i <= 5)
	{
		temp = ft_dlst_new(generator(4, 4), i, h, w);
		ft_dlst_add(&head, temp);
		i++;
	}
	ft_dlst_print_dlst(head);
	ft_dlst_del_all(&head);
	//ft_dlst_print_dlst(head);

}