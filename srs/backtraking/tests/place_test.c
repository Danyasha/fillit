/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:26:43 by btorp             #+#    #+#             */
/*   Updated: 2019/02/14 16:51:28 by btorp            ###   ########.fr       */
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
void two_fig_test()
{
	int		fd;
	t_dlst	*head;
	t_map	*map;

	fd = open("test.fillit", O_RDONLY);
	head = ft_validate_main(fd);
	print_map(head->tetra);
	print_map(head->next->tetra);
	map = map_gen(head, 5);
	tetra_place(map, head, 0, 0);
	tetra_place(map, head->next, 6, 0);
	print_map(map->map);
	close(fd);
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
	close(fd);
}

int	main()
{
	// printf("BASIC TEST:\n");
	// basic_test();
	// printf("BASIC TEST IS OVER:\n");
	printf("2 FIGURE  TEST:\n");
	two_fig_test();
	printf("2 FIGURE  TEST:\n");
	return (0);
}