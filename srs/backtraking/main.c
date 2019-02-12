/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:27:51 by btorp             #+#    #+#             */
/*   Updated: 2019/02/12 16:02:19 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtraking.h"

int		main(int argn, char **argv)
{
	int	fd;
	t_dlst	*head;

	if (argn != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(head = ft_validate_main(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	backtraking_main(&head);
	close(fd);
	return (0);
}