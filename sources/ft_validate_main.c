/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:54:58 by btorp             #+#    #+#             */
/*   Updated: 2019/02/19 21:51:35 by btorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static	int			free_matrix(char ***s)
{
	int		i;
	char	**temp;

	temp = *s;
	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(*s);
	*s = NULL;
	return (1);
}

static	int			makematrix(char ***t, int n)
{
	int	i;

	i = 0;
	*t = (char**)malloc(sizeof(char*) * n);
	while (i < n)
		(*t)[i++] = NULL;
	return (1);
}

static	int			check_one(int fd, t_dlst **t)
{
	int		i;
	char	**tetra;
	int		rd;

	i = 0;
	makematrix(&tetra, 5);
	while (i < 4)
	{
		rd = get_next_line(fd, &tetra[i]);
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
	else if (free_matrix(&tetra))
		return (-1);
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
			return (ft_dlst_del_all(&head));
		rd = get_next_line(fd, &buf);
		if (rd != 0 && buf && buf[0] != '\0')
		{
			free(buf);
			buf = NULL;
			return (ft_dlst_del_all(&head));
		}
		free(buf);
		buf = NULL;
		if (!rd)
			break ;
	}
	if (ft_dlst_find(head, 26))
		return (ft_dlst_del_all(&head));
	return (head);
}
