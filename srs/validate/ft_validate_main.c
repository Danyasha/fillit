/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/14 21:16:14 by btorp            ###   ########.fr       */
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

static	void		free_matrix(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free(*(s)[i]);
		(*s)[i] = NULL;
	}
	free(*s);
	*s = NULL;
}

static	int			check_one(int fd, t_dlst **t)
{
	int		i;
	char	**tetra;
	int		rd;

	i = 0;
	tetra = (char**)malloc(sizeof(char*) * 5);
	tetra[4] = NULL;
	while (i < 4)
	{
		rd = get_next_line(fd, &tetra[i]);
		// printf("tetra[%i] = |%s|\n", i, tetra[i]);
		if (rd <= 0 || !check_string(tetra[i]))
		{
			free_matrix(&tetra);
			return (-1);
		}
		i++;
	}
	rd = ft_check_tetra(tetra);
	if (rd)
		ft_add_tetra(tetra, t);
	else
	{
		free_matrix(&tetra);
		return (-1);
	}
	free_matrix(&tetra);
	return (1);
}

t_dlst				*ft_validate_main(int fd)
{
	t_dlst	*head;
	char	*buf;
	int		rd;

	head = NULL;
	while ((rd = check_one(fd, &head)))
	{
		if (rd == -1)
			return (NULL);
		rd = get_next_line(fd, &buf);
		if (rd == 0 && ft_strlen(buf))
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		if (!rd)
			break ;
	}
	free(buf);
	buf = NULL;
	return (head);
}
