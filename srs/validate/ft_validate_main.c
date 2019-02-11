/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/11 22:00:03 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static	int			check_string(char *line)
{
	if (ft_strlen(line) != 4)
		return (0);
	while (*line)
	{
		if (*line != '.' && *line != '#')
			return (0);
		line++;
	}
	return (1);
}

static	t_dlst		*returnandfree(char ***lines, t_dlst **t)
{
	int	i;

	i = 0;
	if (*lines)
	{
		while ((*lines)[i])
		{
			free((*lines)[i]);
			(*lines)[i] = NULL;
			i++;
		}
		free(*lines);
		*lines = NULL;
	}
	return (*t);
}

static	char		**makearray(size_t t)
{
	char	**s;

	s = (char**)malloc(sizeof(char*) * t);
	s[t - 1] = NULL;
	return (s);
}

t_dlst				*ft_validate_main(int fd)
{
	char	**lines;
	char	*line;
	t_dlst	*tetras;
	int		i;

	tetras = NULL;
	lines = makearray(5);
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (check_string(line))
			lines[i++] = line;
		else
			return (NULL);
		if (i == 4 && ft_check_tetra(lines))
		{
			ft_add_tetra(&lines, &tetras);
			i = 0;
			if (get_next_line(fd, &line) != 0 && line[0])
				return (NULL);
		}
	}
	if (ft_dlst_find(tetras, 0) && !(ft_dlst_find(tetras, 26)) && line[0])
		return (returnandfree(&lines, &tetras));
	return (NULL);
}
