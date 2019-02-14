/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/14 18:02:02 by btorp            ###   ########.fr       */
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

// static	t_dlst		*returnandfree(char ***lines, t_dlst **t)
// {
// 	int	i;

// 	i = 0;
// 	if (*lines)
// 	{
// 		while ((*lines)[i])
// 		{
// 			free((*lines)[i]);
// 			(*lines)[i] = NULL;
// 			i++;
// 		}
// 		free(*lines);
// 		*lines = NULL;
// 	}
// 	return (*t);
// }

static	char		**makearray(size_t t)
{
	char	**s;

	s = (char**)malloc(sizeof(char*) * t);
	s[t - 1] = NULL;
	return (s);
}

static	void		shit(t_dlst **a, char ***b, int *c)
{
	*a = NULL;
	*b = makearray(5);
	*c = 0;
}

t_dlst				*ft_validate_main(int fd)
{
	char	**lines;
	char	*line;
	t_dlst	*tetras;
	int		i;

	shit(&tetras, &lines, &i);
	while (get_next_line(fd, &line))
	{
		if (check_string(line))
			lines[i++] = line;
		else
			return (NULL);
		if (i == 4)
		{
			if (ft_check_tetra(lines) && !(i = 0))
				ft_add_tetra(&lines, &tetras);
			else
				return (NULL);
			if (get_next_line(fd, &line) != 0 && line[0])
				return (NULL);
			for (int g = 0; g <= 3; g++)
				free(lines[g]);
		}
	}
	if (ft_dlst_find(tetras, 0) && !(ft_dlst_find(tetras, 26)) && line)
	{
		free(lines);
		return (tetras);
	}
	return (NULL);
}
