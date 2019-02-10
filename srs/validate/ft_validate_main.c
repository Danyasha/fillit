/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/10 18:25:06 by pcollio-         ###   ########.fr       */
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

	count = 0;
	while (1)
	{
		i = 0;
		lines = (char**)malloc(sizeof(char*) * 5);
		lines[4] = NULL;
		get_next_line(fd, &line);
		if (get_next_line(fd, &line) == 0 && count >= 1 && count <= 26)
			return (tetras); // будет утечка lines и line
		while (i < 4)
		{
			check_string(line);
			if (get_next_line(fd, &line) <= 0 || !check_string(line) || count > 26)
				return (terminate(lines, line, tetras));
			lines[i] = ft_memcpy(lines[i], line, 5);
			i++;
		}
		if (!ft_check_tetra(lines) || get_next_line(fd, &line) <= 0 || !ft_strlen(line))
			return (terminate(lines, line, tetras));
		else
			count += ft_add_tetra(lines, &tetras);	
	}
}
