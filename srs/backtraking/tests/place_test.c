/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:26:43 by btorp             #+#    #+#             */
/*   Updated: 2019/02/13 20:58:01 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../backtraking.h"
void print_map(char **c)
{
	int	i;

	i = 0;
	while(c[i])
		printf("%s\n", c[i++]);
}
void	basic_test()
{
	int		fd;
	t_dlst	*head;
	t_map	*map;

	fd = open("test.fillit", O_RDONLY);
	head = ft_validate_main(fd);
	map = map_gen(head, 3);
	tetra_place(map, head, 1, 1);
	print_map(map->map);
}

int	main()
{
	printf("BASIC TEST:\n");
	basic_test();
	printf("BASIC TEST IS OVER:\n");
	return (0);
}