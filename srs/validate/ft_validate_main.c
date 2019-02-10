/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 19:29:02 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

static	int			check_string(char *line)
{
	if (ft_strlen(line) != 4)
		return (0);
	while (*line)
	{
		if (*line != '.' || *line != '#')
			return (0);
		line++;
	}
	return (1);
}

static	t_dlst		*terminate(char	**lines, char *line, t_dlst *head)
{
	int i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		lines[i] = NULL;
	}
	free(lines);
	lines = NULL;
	free(line);
	line = NULL;
	ft_dlst_del_all(&head);
	return (NULL);
}

t_dlst				*ft_validate_main(int fd)
{
	char	**lines;
	char	*line;
	t_dlst	*tetras;
	int		i;
	int		count;

	lines = (char**)malloc(sizeof(char*) * 5);
	lines[4] = NULL;
	count = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i == 4 && ft_strncpy(line, "\n", 2) && ft_check_tetra(lines))
		{
			ft_add_tetra(&lines, &tetras);
			i = 0;
			count++;
		}
		else if (check_string(line))
			lines[i++] = line;
		else
			return (NULL);
	}
	if (count > 0 && count < 25)
		return (tetras);
	return (NULL);
}
