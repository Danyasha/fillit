/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:29:44 by btorp             #+#    #+#             */
/*   Updated: 2019/02/13 20:44:24 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../backtraking.h"

int	main(void)
{
	int		fd;
	t_dlst	*head;
	t_map	*map;
	int		i;
	fd = open("test.fillit", O_RDONLY);
	head = ft_validate_main(fd);
	if (head == NULL)
	{
		printf("INVALID FILE\n");
		return (0);
	}
	map = map_gen(head, 0);
	i = 0;
	printf("map->n = %i\n", map->n);
	while(map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	map = map_gen(head, 3);
	i = 0;
	printf("map->n = %i\n", map->n);
	while(map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	close(fd);
}