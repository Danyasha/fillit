/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_tetra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:47:15 by btorp             #+#    #+#             */
/*   Updated: 2019/02/11 21:39:19 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../validate.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;
	int		f;

	f = 0;
	fd = open("test.fillit", O_RDONLY);
	lines = (char**)malloc(sizeof(char*)*5);
	lines[4] = NULL;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (i == 4)
		{
			if(ft_check_tetra(lines) == 0)
			{
				f++;
				printf("invalid\n");
				for (int g = 0; g < 4; g++)
					printf("%s\n", lines[g]);
			}
			else
			{
				printf("valid\n");
				for (int g = 0; g < 4; g++)
					printf("%s\n", lines[g]);
			}
			
			i = 0;
			continue ;
		}
		lines[i] = line;
		i++;
	}
	if (f)
		printf("Count of non-valid tetras = %i\n", f);
	else 
		printf("All tetras are valid\n");
	close(fd);
	return (0);
}