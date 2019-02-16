/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:29:44 by btorp             #+#    #+#             */
/*   Updated: 2019/02/16 15:49:01 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../backtraking.h"
void	map_free(t_map **map)
{
	int	i;

	i = 0;
	while((*map)->map[i])
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	(*map)->map = NULL;
	free(*map);
	*map = NULL;
}

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
	map = map_gen(4);
	i = 0;
	printf("map->n = %i\n", map->n);
	while(map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	map_free(&map);
	map = map_gen(5);
	i = 0;
	printf("map->n = %i\n", map->n);
	while(map->map[i] != NULL)
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	map_free(&map);
	ft_dlst_del_all(&head);
	close(fd);
}